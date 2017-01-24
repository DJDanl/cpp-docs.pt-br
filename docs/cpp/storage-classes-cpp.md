---
title: "Classes de armazenamento (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "thread_local_cpp"
  - "external_cpp"
  - "static_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "classes de armazenamento, conceitos básicos"
ms.assetid: f10e1c56-6249-4eb6-b08f-09ab1eef1992
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de armazenamento (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um *classe de armazenamento* no contexto do C\+\+ declarações de variável é um especificador de tipo que controla o tempo de vida, a vinculação e a memória local de objetos e.  Um determinado objeto pode ter apenas uma classe de armazenamento.  Variáveis definidas em um bloco têm armazenamento automático, a menos que especificado de outra forma usando o `extern`, `static`, ou `thread_local` especificadores.  Variáveis e objetos automáticos não têm nenhuma vinculação; eles não são visíveis para o código fora do bloco.  
  
 **Observações**  
  
1.  A palavra\-chave [mutable](../cpp/mutable-data-members-cpp.md) pode ser considerada um especificador de classe de armazenamento.  No entanto, ela só está disponível na lista de membros de uma definição de classe.  
  
2.  Começando com [!INCLUDE[cpp_dev10_long](../Token/cpp_dev10_long_md.md)], o `auto` palavra\-chave não é mais um especificador de classe de armazenamento C\+\+ e o `register` palavra\-chave é preterida.  
  
-   [Estático](#static)  
  
-   [extern](#extern)  
  
-   [thread\_local](#thread_local)  
  
## estático  
 O `static` palavra\-chave pode ser usada para declarar variáveis e funções com escopo global, o escopo de namespace e o escopo da classe.  Variáveis estáticas também podem ser declaradas no escopo local.  
  
 Duração estática significa que o objeto ou a variável são alocados quando o programa inicia e desalocados quando o programa termina.  Vinculação externa significa que o nome da variável é visível fora do arquivo em que a variável é declarada.  Por outro lado, a vinculação externa significa que o nome não é visível fora do arquivo em que a variável é declarada.  Por padrão, um objeto ou variável que é definido no namespace global tem duração estática e vinculação externa.  A palavra\-chave `static` pode ser usada nas seguintes situações:  
  
1.  Ao declarar uma variável ou função no escopo do arquivo \(escopo global e\/ou de namespace\), a palavra\-chave `static` especifica que a variável ou função possui vinculação interna.  Ao declarar uma variável, a variável tem duração estática, e o compilador a inicializa com o valor 0 a menos que você especifique outro valor.  
  
2.  Ao declarar uma variável em uma função, a palavra\-chave `static` especifica que a variável manterá seu estado entre as chamadas para essa função.  
  
3.  Ao declarar um membro de dados em uma declaração de classe, a palavra\-chave `static` especifica que uma cópia do membro é compartilhada por todas as instâncias da classe.  Um membro de dados static deve ser definido no escopo do arquivo.  Um membro de dados integral que você declara como `const` `static` pode ter um inicializador.  
  
4.  Ao declarar uma função de membro em uma declaração de classe, a palavra\-chave `static` especifica que a função é compartilhada por todas as instâncias da classe.  Uma função de membro static não pode acessar um membro de instância porque a função não tem um ponteiro `this` implícito.  Para acessar um membro de instância, declare a função com um parâmetro que seja um ponteiro ou uma referência de instância.  
  
5.  Não é possível declarar os membros de uma união como estáticos.  No entanto, uma união anônima globalmente declarada deve ser explicitamente declarada como `static`.  
  
 O exemplo a seguir mostra como uma variável declarada `static` em uma função mantém o estado entre chamadas para a função.  
  
```  
// static1.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
void showstat( int curr ) {  
   static int nStatic;    // Value of nStatic is retained  
                          // between each function call  
   nStatic += curr;  
   cout << "nStatic is " << nStatic << endl;  
}  
  
int main() {  
   for ( int i = 0; i < 5; i++ )  
      showstat( i );  
}  
```  
  
  **nStatic é 0**  
**nStatic é 1**  
**nStatic é 3**  
**nStatic é 6**  
**nStatic é 10** O exemplo a seguir mostra o uso de `static` em uma classe.  
  
```  
// static2.cpp  
// compile with: /EHsc  
#include <iostream>  
  
using namespace std;  
class CMyClass {  
public:  
   static int m_i;  
};  
  
int CMyClass::m_i = 0;  
CMyClass myObject1;  
CMyClass myObject2;  
  
int main() {  
   cout << myObject1.m_i << endl;  
   cout << myObject2.m_i << endl;  
  
   myObject1.m_i = 1;  
   cout << myObject1.m_i << endl;  
   cout << myObject2.m_i << endl;  
  
   myObject2.m_i = 2;  
   cout << myObject1.m_i << endl;  
   cout << myObject2.m_i << endl;  
  
   CMyClass::m_i = 3;  
   cout << myObject1.m_i << endl;  
   cout << myObject2.m_i << endl;  
}  
```  
  
  **0**  
**0**  
**1**  
**1**  
**2**  
**2**  
**3**  
**3** O exemplo a seguir mostra uma variável local declarada `static` em uma função de membro.  A variável estática está disponível para o programa inteiro; todas as instâncias do tipo compartilham a mesma cópia da variável estática.  
  
```  
// static3.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
struct C {  
   void Test(int value) {  
      static int var = 0;  
      if (var == value)   
         cout << "var == value" << endl;  
      else  
         cout << "var != value" << endl;  
  
      var = value;  
   }  
};   
  
int main() {  
   C c1;  
   C c2;  
   c1.Test(100);  
   c2.Test(100);  
}  
```  
  
  **var \! \= valor**  
**var \=\= valor** Começando no C\+\+ 11, uma inicialização de variável local estática tem garantia de ser thread\-safe.  Esse recurso é chamado, às vezes, *estatísticas mágicas*.  No entanto, em um aplicativo multithreaded todas as atribuições subsequentes devem ser sincronizadas.  O recurso de thread\-safe estática pode ser desabilitado usando o sinalizador \/Zc:threadSafeInit\-para evitar assumir uma dependência do CRT.  
  
## extern  
 Os objetos e variáveis declaradas como `extern` declaram um objeto que é definido em outra unidade de tradução ou em um escopo delimitador como tendo vinculação externa.  
  
 A declaração de variáveis **const** com a classe de armazenamento `extern` força o vínculo externo da variável.  Uma inicialização de uma variável **extern const** é permitida na unidade de tradução de definição.  As inicializações das unidades de tradução diferentes da unidade de tradução de definição geram resultados indefinidos.  Para obter mais informações, consulte [Usando extern para especificar ligação](../cpp/using-extern-to-specify-linkage.md)  
  
 O código a seguir mostra duas declarações `extern`, `DefinedElsewhere` \(que se refere a um nome definido em uma unidade de tradução diferente\) e `DefinedHere` \(que se refere a um nome definido em um escopo delimitador\):  
  
```  
// external.cpp  
// defined in another translation unit  
extern int DefinedElsewhere;     
int main() {  
   int DefinedHere;   
   {  
      // refers to DefinedHere in the enclosing scope  
      extern int DefinedHere;  
    }  
}  
```  
  
## thread\_local \(C \+ \+ 11\)  
 Uma variável declarada com o `thread_local` especificador é acessível somente no thread no qual ele é criado.  A variável é criada quando o thread é criado e destruído quando o thread é destruído.  Cada thread tem sua própria cópia da variável.  No Windows, `thread_local` é funcionalmente equivalente à específicos do Microsoft [declspec \(thread\)](../cpp/thread.md) atributo.  
  
```  
thread_local float f = 42.0; //global namespace  
  
struct C // cannot be applied to type definition  
{  
thread_local int i; //local  
thread_local static char buf[10]; // local and static  
};  
  
void DoSomething()  
{  
thread_local C my_struct; // Apply  thread_local to a variable  
}  
```  
  
1.  O especificador de thread\_local pode ser combinado com `static` ou `extern`.  
  
2.  Você pode aplicar `thread_local` somente para dados declarações e definições; **thread\_local** não pode ser usado em declarações de função ou definições.  
  
3.  O uso de `thread_local` podem interferir com [carregamento com atraso](../build/reference/linker-support-for-delay-loaded-dlls.md) de importações de DLL**.**  
  
4.  Em sistemas XP, `thread_local` podem não funcionar corretamente se uma DLL usa `thread_local` dados e ele é carregado dinamicamente via LoadLibrary.  
  
5.  Você pode especificar `thread_local` apenas em itens de dados com duração de armazenamento estático.  Isso inclui objetos de dados globais \(**static** e `extern`\), objetos estáticos locais e membros de dados estáticos de classes.  Você não pode declarar objetos de dados automática com **thread\_local**.  
  
6.  Você deve especificar `thread_local` para a declaração e a definição de um objeto de thread local, se a declaração e a definição ocorrem no mesmo arquivo ou arquivos separados.  
  
 No Windows, `thread_local` é funcionalmente equivalente à  [\_\_declspec\(thread\)](../cpp/thread.md) exceto que \_\_declspec\(thread\) pode ser aplicado a uma definição de tipo e é válido em código C.  Sempre que possível, use `thread_local` porque ele faz parte do padrão C\+\+ e, portanto, mais portátil.  
  
 Para obter mais informações, consulte [Armazenamento local de thread \(TLS\)](../parallel/thread-local-storage-tls.md).  
  
## register  
 No C\+\+ 11, o **registrar** palavra\-chave é preterida.  Especifica que a variável deve ser armazenado no registro do computador, se possível.  Apenas os argumentos de função e variáveis locais podem ser declarados com a classe de armazenamento de registro.  
  
```  
register int num;  
```  
  
 Como as variáveis automáticas, as variáveis de registro só persistem até o final do bloco no qual elas estão declaradas.  
  
 O compilador não honra as solicitações do usuário para variáveis de registro; em vez disso, faz suas próprias opções de registro quando as otimizações globais estão ativadas.  No entanto, qualquer outra semântica associada à palavra\-chave [registro](http://msdn.microsoft.com/pt-br/5b66905a-2f7f-4918-bb55-5e66d4bc50f9) é honrada pelo compilador.  
  
 Se o operador address\-of \(**&**\) é usado em um objeto que é declarado com o registro, o compilador deve colocar o objeto na memória, em vez de um registro.  
  
## Exemplo: automáticas vs.inicialização estática  
 Um objeto ou uma variável local automática são inicializados cada vez que o fluxo de controle alcança sua definição.  Um objeto ou uma variável local estática são inicializados na primeira vez que o fluxo de controle alcança sua definição.  
  
 Considere o exemplo a seguir, que define uma classe que registra a inicialização e a destruição de objetos e depois define três objetos, `I1`, `I2` e `I3`:  
  
```  
// initialization_of_objects.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <string.h>  
using namespace std;  
  
// Define a class that logs initializations and destructions.  
class InitDemo {  
public:  
   InitDemo( const char *szWhat );  
   ~InitDemo();  
  
private:  
   char *szObjName;  
   size_t sizeofObjName;  
};  
  
// Constructor for class InitDemo  
InitDemo::InitDemo( const char *szWhat ) :  
   szObjName(NULL), sizeofObjName(0) {  
   if( szWhat != 0 && strlen( szWhat ) > 0 ) {  
      // Allocate storage for szObjName, then copy  
      // initializer szWhat into szObjName, using  
      // secured CRT functions.  
      sizeofObjName = strlen( szWhat ) + 1;  
  
      szObjName = new char[ sizeofObjName ];  
      strcpy_s( szObjName, sizeofObjName, szWhat );  
  
      cout << "Initializing: " << szObjName << "\n";  
   }  
   else  
      szObjName = 0;  
}  
  
// Destructor for InitDemo  
InitDemo::~InitDemo() {  
   if( szObjName != 0 ) {  
      cout << "Destroying: " << szObjName << "\n";  
      delete szObjName;  
   }  
}  
  
// Enter main function  
int main() {  
   InitDemo I1( "Auto I1" ); {  
      cout << "In block.\n";  
      InitDemo I2( "Auto I2" );  
      static InitDemo I3( "Static I3" );  
   }  
   cout << "Exited block.\n";  
}  
```  
  
  **Inicializando: I1 automático**  
**No bloco.  Inicializando: I2 automático**  
**Inicializando: I3 estático**  
**Destruindo: I2 automático**  
**Bloco encerrado.  Destruindo: I1 automático**  
**Destruindo: I3 estático**  O código anterior demonstra como e quando os objetos `I1`, `I2` e `I3` são inicializados e quando eles são destruídos.  
  
 Há vários pontos a serem observados sobre o programa.  
  
 Primeiro, `I1` e `I2` são destruídos automaticamente quando o fluxo de controle sai do bloco em que estão definidos.  
  
 Depois, em C\+\+, não é necessário declarar objetos ou variáveis no início de um bloco.  Além disso, esses objetos são inicializados somente quando o fluxo de controle atinge suas definições.  \(`I2` e `I3` são exemplos de tais definições.\) A saída mostra exatamente quando eles são inicializados.  
  
 Por fim, as variáveis locais estáticas, como `I3`, retêm seus valores enquanto o programa dura, mas são destruídas quando o programa é encerrado.  
  
## Consulte também  
 [Declarações e definições](../cpp/declarations-and-definitions-cpp.md)