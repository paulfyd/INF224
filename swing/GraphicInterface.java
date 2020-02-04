import javax.swing.*;
import javax.swing.border.*;
import java.awt.event.*;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.io.*;
import java.net.*;
import java.awt.GridLayout;



public class GraphicInterface extends JFrame {

    private static final long serialVersionUID = 1L;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    private static Socket sock;
    private static  BufferedReader input;
    private static BufferedWriter output;
    JButton button1,button2,button3;
    JTextArea textZone;
    JPanel panel;
    JScrollPane scroll;
    static JTextField textField;
    JMenuBar menuBar;
    JMenu menu;
    JMenuItem menuItem;
    static String answer;

    ///
    /// Lit une requete depuis la zone textField et les boutons, envoie cette requete au serveur,
    /// recupere sa reponse et l'affiche sur le Terminal, ou la joue.
    /// Noter que le programme bloque si le serveur ne repond pas.

    public void serverControl(String request) {
        // Envoyer la requete au serveur
        try {
            request += "\n";  // ajouter le separateur de lignes
            output.write(request, 0, request.length());
            output.flush();
            }
        catch (java.io.IOException e) {
            System.err.println("Client: Couldn't send message: " + e);
            JOptionPane.showMessageDialog(null, "Client: Couldn't send message","Error",JOptionPane.ERROR_MESSAGE);
            }

        try {
            answer = input.readLine();
            System.out.println(answer);
             if(answer.equals("No multimedia found ;No group found "))
                     JOptionPane.showMessageDialog(null, "No Media or Group Found","Error",JOptionPane.ERROR_MESSAGE);
             else if(answer.equals("No multimedia to play"))
                     JOptionPane.showMessageDialog(null, "No Media or Group to play","Error",JOptionPane.ERROR_MESSAGE);
             else {
                     textZone.append(answer.replace(";", "\n")+"\n");
                  }
             }
             catch (java.io.IOException e) {
               System.err.println("Client: Couldn't receive message: " + e);
             //  JOptionPane.showMessageDialog(null, "Client: Couldn't receive message","Error",JOptionPane.ERROR_MESSAGE);
             }
            }



     // Implementation du bouton permettant de chercher un élément dans notre BDD


    class text1 extends AbstractAction{
             public text1(){};

             public void actionPerformed(ActionEvent e){
                 textZone.append(textField.getText()+"\n");
                 serverControl("Search "+textField.getText());
                 textField.setText("");
             }

    // Implementation du bouton permettant de jouer un élément dans notre BDD

    }
    class text2 extends AbstractAction{
             public text2(){};

             public void actionPerformed(ActionEvent e){
                 textZone.append(textField.getText()+"\n");
                 serverControl("Play "+textField.getText());
                 textField.setText("");
              }
    }


    // Implementation du bouton permettant de quitter la JFrame
    class quitButton extends AbstractAction{
             public quitButton() {}

             public void actionPerformed(ActionEvent e){
                     System.exit(0);
             }
    }

    //Instanciation des 3 boutons
    quitButton quitAct= new quitButton();
    text1 bbtnAct =  new text1();
    text2 bbtn2Act =  new text2();

    // Methode principale, appelee dans main
    public GraphicInterface() {

        // Creation des bouttons

        button1 = new JButton(bbtnAct);
        button1.setText("SEARCH");
        button2 = new JButton(bbtn2Act);
        button2.setText("PLAY");
        button3 = new JButton(quitAct);
        button3.setText("QUIT");
        textField = new JTextField("Votre Multimedia");
        textZone = new JTextArea(5,5);
        textZone.setEditable(false);
        scroll = new JScrollPane(textZone);
        setLayout(new BorderLayout());

        // Creation du panel

        panel = new JPanel();
        panel.setLayout(new GridLayout(1, 4));
        panel.add(textField);
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);

        // Creation du menu

        menuBar = new JMenuBar();
        menu = new JMenu("Menu");
        menu.setMnemonic(KeyEvent.VK_A);
        menu.getAccessibleContext().setAccessibleDescription("The only menu in this program that has menu items");
        menuBar.add(menu);
        menuItem = new JMenuItem(bbtnAct);
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
        menuItem.setText("Search");
        menu.add(menuItem);
        menuItem = new JMenuItem(bbtn2Act);
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_2, ActionEvent.ALT_MASK));
        menuItem.setText("Play");
        menu.add(menuItem);
        menuItem = new JMenuItem(quitAct);
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_3, ActionEvent.ALT_MASK));
        menuItem.setText("Exit");
        menu.add(menuItem);
        this.setJMenuBar(menuBar);

        setSize(new Dimension(700,300));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Graphic Interface");
        add(panel, BorderLayout.SOUTH);
        add(scroll, BorderLayout.CENTER);
        pack();
        //setMinimumSize(new Dimension(700,300));
        setVisible(true);
    }

    public static void main(String argv[] ) throws IOException{

        GraphicInterface graphicInterface = new GraphicInterface();

        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        if (argv.length >=1) host = argv[0];
        if (argv.length >=2) port = Integer.parseInt(argv[1]);
        try {
             sock = new java.net.Socket(host, port);
             }
             catch (java.net.UnknownHostException e) {
               System.err.println("Client: Couldn't find host "+host+":"+port);
               JOptionPane.showMessageDialog(null, "Client: Couldn't find host "+host+":"+port,"Error",JOptionPane.ERROR_MESSAGE);
               throw e;
             }
             catch (java.io.IOException e) {
               System.err.println("Client: Couldn't reach host "+host+":"+port);
               JOptionPane.showMessageDialog(null, "Client: Couldn't reach host "+host+":"+port,"Error",JOptionPane.ERROR_MESSAGE);
               throw e;
             }
             try {
               input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
               output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
             }
             catch (java.io.IOException e) {
               System.err.println("Client: Couldn't open input or output streams");
               JOptionPane.showMessageDialog(null, "Client: Couldn't open input or output streams","Error",JOptionPane.ERROR_MESSAGE);
               throw e;
             }
        System.out.println("Client connected to "+host+":"+port);

    }

}
