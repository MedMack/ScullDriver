#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> /* pour le support des pilotes charactere*/
 
//ouverture
int pr_open(struct inode *pinode, struct file *pfile) {
  printk (KERN_ALERT "Dans la fonction %s \n", __FUNCTION__);
  return 0;
}
 
//lecture
ssize_t pr_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset) {
  printk (KERN_ALERT "Dans la fonction %s \n", __FUNCTION__);
  return 0;
}
 
//ecriture
ssize_t pr_write(struct file *pfile, const char __user *buffer, size_t length, loff_t *offset) {
  printk (KERN_ALERT "Dans la fonction %s \n", __FUNCTION__);
  return length;
}
 
//fermeture
int pr_close(struct inode *pinode, struct file *pfile) {
  printk (KERN_ALERT "Dans la fonction %s \n", __FUNCTION__);
  return 0;
}
 
struct file_operations fops = {
  //liste des opérations et les noms des fonctions
 read     : pr_read,
 write    : pr_write,
 open     : pr_open,
 release  : pr_close,
};
 
int pr_module_init (void) {
  printk (KERN_ALERT " Dans le module init\n");
  // chargement dans le kernel et indique qu'il s'agit d'un pilote charactere
  register_chrdev(240 /*nombre majeur*/,
                  "Projet_Char_Dev" /*nom du driver*/,
                  &fops /*fichier d'operations*/);
  return 0;
}
 
int pr_module_exit (void) {
  printk (KERN_ALERT " Dans le module exit\n");
  // déchargement
  unregister_chrdev(240, "Projet_Char_Dev");
}
 
module_init(pr_module_init);
module_exit(pr_module_exit);
