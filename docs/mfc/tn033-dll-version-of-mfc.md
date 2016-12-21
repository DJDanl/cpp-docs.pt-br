---
title: "TN033: vers&#227;o DLL do MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.dll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Biblioteca AFXDLL"
  - "Versão de DLL do MFC [C++]"
  - "DLLs [C++], MFC"
  - "DLLs MFC [C++], DLLs de extensão de gravação"
  - "TN033"
ms.assetid: b6f1080b-b66b-4b1e-8fb1-926c5816392c
caps.latest.revision: 13
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN033: vers&#227;o DLL do MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve como você pode usar bibliotecas de vínculo dinâmico compartilhadas de MFCxx.DLL e de MFCxxD.DLL \(onde x é o número da versão de MFC\) com aplicativos MFC e DLL da extensão.  Para obter mais informações sobre dlls regulares, consulte [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md).  
  
 Observe que essa técnica abrange três aspectos da DLL.  Os dois dos mais recentes são mais para usuários avançados:  
  
-   [Como você cria uma DLL da extensão MFC](#_mfcnotes_how_to_write_an_mfc_extension_dll)  
  
-   [Como você cria um aplicativo de MFC que usa a versão da DLL MFC](#_mfcnotes_writing_an_application_that_uses_the_dll_version)  
  
-   [Como as bibliotecas de vínculo dinâmico\) nativa MFC compartilhadas são implementadas](#_mfcnotes_how_the_mfc30.dll_is_implemented)  
  
 Se você estiver interessado na compilação que uma DLL que usa o MFC que pode ser usado com aplicativos não MFC \(isso é chamado uma DLL comum\), consulte [Observação 11 técnica](../mfc/tn011-using-mfc-as-part-of-a-dll.md).  
  
## Visão geral do suporte de MFCxx.DLL: Terminologia e arquivos  
 **Regular DLL**: Você usa uma DLL normal para criar uma DLL autônomo usando qualquer uma das classes MFC.  As interfaces pelo limite de Aplicativo\/DLL são interfaces de C “2.0”, e o aplicativo cliente não precisa ser um aplicativo MFC.  
  
 Essa é a versão de suporte da DLL suporte em MFC 1,0.  É descrito em [Observação 11 técnica](../mfc/tn011-using-mfc-as-part-of-a-dll.md) e os conceitos avançados MFC [DLLScreenCap](../top/visual-cpp-samples.md)de exemplo.  
  
> [!NOTE]
>  A partir da versão 4,0 do Visual C\+\+, o termo **USRDLL** é obsoleto e foi substituído por uma DLL normal que vincula estaticamente MFC ao.  Você também pode criar uma DLL normal que vincula dinamicamente ao MFC.  
  
 \(MFC O 3,0 e anterior\) oferece suporte a DLL normais com qualquer nova funcionalidade que inclui o OLE e as classes da base de dados.  
  
 **AFXDLL**: Isso também é referenciado como a versão compartilhada as bibliotecas de MFC.  Este é o novo suporte a DLL adicionado MFC em 2,0.  A própria biblioteca MFC estiver em um número de DLL \(descritos abaixo\) e um aplicativo cliente ou uma DLL vinculam dinamicamente os DLL que requer.  As interfaces pelo limite de application\/DLL são interfaces da classe de C\+\+\/MFC.  O aplicativo cliente DEVE ser um aplicativo MFC.  Isso oferece suporte a toda a funcionalidade de exceção: 3,0 \(MFC UNICODE não oferece suporte às classes da base de dados\).  
  
> [!NOTE]
>  A partir da versão 4,0 do Visual C\+\+, esse tipo de DLL é chamado de “DLL extensão.”  
  
 Essa observação MFCxx.DLL usará para se referir ao conjunto inteiro da DLL MFC, incluindo:  
  
-   Depuração: MFCxxD.DLL \(combinado\) e MFCSxxD.LIB \(estático\).  
  
-   Versão: MFCxx.DLL \(combinado\) e MFCSxx.LIB \(estático\).  
  
-   Depuração Unicode: MFCxxUD.DLL \(combinado\) e MFCSxxD.LIB \(estático\).  
  
-   Versão de Unicode: MFCxxU.DLL \(combinado\) e MFCSxxU.LIB \(estático\).  
  
> [!NOTE]
>  As bibliotecas de MFCSxx U \[\] \[\] De .LIB são usadas em conjunto com as dlls MFC compartilhados.  Essas bibliotecas contêm código que deve ser vinculado estaticamente no aplicativo ou para a DLL.  
  
 Links de aplicativo nas bibliotecas da importação:  
  
-   Depuração: MFCxxD.LIB  
  
-   Versão: MFCxx.LIB  
  
-   Depuração Unicode: MFCxxUD.LIB  
  
-   Versão de Unicode: MFCxxU.LIB  
  
 “Um DLL de extensão MFC” é uma DLL compilado em MFCxx.DLL \(e\/ou os outros DLL compartilhados MFC\).  É a arquitetura de componente MFC retrocede em.  Se você deve derivar uma classe útil de uma classe de MFC, ou cria outra MFC\- como o conjunto de ferramentas, você pode colocá\-lo em uma DLL.  A DLL que usa MFCxx.DLL, como faz o aplicativo cliente final.  Isso permite classes reutilizáveis folha, classes base, reutilizáveis e classes reutilizáveis de exibição\/documento.  
  
## Os profissionais \- e \- em  
 Por que você deve usar a versão compartilhada MFC?  
  
-   Usar a biblioteca compartilhada pode resultar em aplicativos menores \(um aplicativo mínimo que usa mais de biblioteca MFC são menores do que 10K\).  
  
-   A versão compartilhada MFC da suporte a DLL de extensão MFC e DLL normais.  
  
-   Criar um aplicativo que usa as bibliotecas compartilhadas MFC é mais rápido do que criando um aplicativo estaticamente vinculado MFC pois não é necessário vincular MFC próprio.  Isso é especialmente verdadeiro nas construções de **DEPURAR** onde o vinculador deverá compactar as informações de depuração — vinculando com uma DLL que já contém informações de depuração, há menos informações de depuração para compactar dentro de seu aplicativo.  
  
 Como você não deve usar a versão compartilhada MFC:  
  
-   Enviar um aplicativo que usa a biblioteca compartilhada requer que você envia a biblioteca de MFCxx.DLL \(e outros\) com o programa.  MFCxx.DLL livremente é redistribuível como muitos DLL, mas ainda deve instalar a DLL no programa de instalação.  Além disso, você deve enviar o MSVCRTxx.DLL, que contém a biblioteca de C \- tempo de execução que é usada por seu programa e pela DLL ele mesmo MFC.  
  
##  <a name="_mfcnotes_how_to_write_an_mfc_extension_dll"></a> Como gravar uma DLL da extensão MFC  
 Uma DLL da extensão MFC é uma DLL que contém as classes e as funções escritas para embelezar a funcionalidade das classes MFC.  Uma DLL da extensão MFC usa as dlls compartilhados MFC da mesma forma que um aplicativo usa para ele, com algumas considerações adicionais:  
  
-   O processo de compilação é semelhante a criar um aplicativo que usa as bibliotecas compartilhadas MFC com quaisquer opções adicionais do compilador e do vinculador.  
  
-   Uma DLL da extensão MFC não tem `CWinApp`\- classe derivada.  
  
-   Uma DLL da extensão MFC deve fornecer `DllMain`especial.  AppWizard fornece uma função de `DllMain` que você possa alterar.  
  
-   Uma DLL da extensão MFC fornecerá geralmente uma rotina de inicialização para criar **CDynLinkLibrary** se a DLL de extensão deseja exportar `CRuntimeClass`es ou recursos para o aplicativo.  Uma classe derivada de **CDynLinkLibrary** pode ser usada se os dados do aplicativo devem ser mantidos pela DLL da extensão.  
  
 Essas considerações são descritas mais detalhadamente em.  Você também deve fazer referência aos conceitos avançados MFC [DLLHUSK](../top/visual-cpp-samples.md) de exemplo ilustra como:  
  
-   Criando um aplicativo usando bibliotecas compartilhadas. \(DLLHUSK.EXE é um aplicativo de MFC que vincula dinamicamente nas bibliotecas de MFC bem como outros DLL\).  
  
-   Criando uma DLL da extensão MFC. \(Observe os sinalizadores especiais como `_AFXEXT` que são usados para criar uma DLL de extensão\)  
  
-   Dois exemplos de DLL de extensão MFC.  Mostra se a estrutura básica de uma DLL da extensão MFC com exporta limitadas \(TESTDLL1\) e outras mostra a exportação de uma interface inteira da classe TESTDLL2 \(\).  
  
 O aplicativo cliente e todas as dlls de extensão devem usar a mesma versão de MFCxx.DLL.  Você deve seguir a convenção da DLL MFC e fornecer uma depuração e vender varejo à versão \(\/release\) do DLL da extensão.  Isso permite programas cliente criar versões de depuração e de varejo de seus aplicativos e depois vincule com a versão apropriada de depuração ou de varejo de todas as dlls.  
  
> [!NOTE]
>  Como os problemas de massacre e exportação do nome do C\+\+, a lista de exportação de uma DLL da extensão podem ser diferentes entre a depuração e as versões de varejo do mesmo DLL e DLL para plataformas diferentes.  O varejo MFCxx.DLL tem cerca de 2000 pontos de entrada exportados; a depuração MFCxxD.DLL tem cerca de 3000 pontos de entrada exportados.  
  
### Observação rápido no gerenciamento de memória  
 A seção gerenciamento de memória denominada “,” próximo do fim desta técnica, observe que descreve a implementação do MFCxx.DLL com a versão compartilhada MFC.  As informações que você precisa saber para implementar apenas uma DLL de extensão é descrita aqui.  
  
 MFCxx.DLL e todas as dlls de extensão carregados no espaço de endereço de um aplicativo cliente usarão o mesmo alocador de memória, a carga de recursos e outros estados “globais” MFC como se estivesse no mesmo aplicativo.  Isso é significativo como as bibliotecas da DLL NÃO\- MFC e as dlls regulares que vinculam estaticamente MFC ao fazer o oposto exato e têm a cada DLL que atribui fora de seu próprio pool de memória.  
  
 Se uma DLL da extensão aloca memória, essa memória pode misturar\-se livremente com qualquer outro objeto atribuído pelo aplicativo.  Além disso, se um aplicativo que usa as bibliotecas compartilhadas MFC falhar, a proteção do sistema operacional o manterá a integridade de qualquer outro aplicativo MFC que compartilha a DLL.  
  
 De maneira semelhante outros estados “globais” MFC, como o arquivo executável atual para carregar recursos do, também são compartilhados entre o aplicativo cliente e todas as dlls de extensão MFC bem como MFCxx.DLL próprio.  
  
### Criando uma DLL da extensão  
 Você pode usar AppWizard para criar um projeto de extensão da DLL MFC, e gerará automaticamente as configurações apropriadas do compilador e do vinculador.  Também era gerenciar uma função de `DllMain` que você possa alterar.  
  
 Se você estiver convertendo um projeto existente a uma DLL da extensão MFC, comece com o padrão é agrupado criando um aplicativo usando a versão compartilhada MFC, então faça o seguinte:  
  
-   Adicionar **\/D\_AFXEXT** aos sinalizadores de compilador.  Na caixa de diálogo propriedades do projeto, selecione o nó C\/C\+\+.  Selecione a categoria de pré\-processador.  Adicionar `_AFXEXT` para macros de definição de campo, separando\-se cada um dos itens com ponto\-e\-vírgula.  
  
-   Remover a opção do compilador de **\/Gy** .  Na caixa de diálogo propriedades do projeto, selecione o nó C\/C\+\+.  Selecione a categoria de geração de código.  Verifique se “para habilitar o com nível que vincula a opção” não está habilitado.  Isso facilitará exportar classes porque o vinculador não removerá as funções não referenciada.  Se o projeto original é usado criar uma DLL vinculado ao normal estaticamente MFC, altere a opção do compilador de **\/MT\[d\]** a **\/MD\[d\]**.  
  
-   Criar uma biblioteca de exportação com a opção de **\/DLL** VINCULAR.  Isso será definido quando você cria um novo destino, especificando a biblioteca de vínculo dinâmico\) nativa do Win32 como o tipo de destino.  
  
### Modificando arquivos de cabeçalho  
 O objetivo de um DLL de extensão é geralmente exportar alguma funcionalidade comum a um ou mais aplicativos que podem usar essa funcionalidade.  Isso ferve para baixo para exportar as classes e as funções globais que estão disponíveis para aplicativos cliente.  
  
 Para fazer isso você deve garantir que cada uma das funções de membro está marcada como a importação ou exportação conforme apropriado.  Isso requer declarações especiais: **\_\_declspec\(dllexport\)** e **\_\_declspec\(dllimport\)**.  Quando suas classes são usadas por aplicativos cliente, você desejar\-los a ser declarado como **\_\_declspec\(dllimport\)**.  A DLL próprio de extensão está sendo compilado, deve ser declarado como **\_\_declspec\(dllexport\)**.  Além disso, as funções de fato devem ser exportadas, de modo que os programas cliente se associem eles no tempo de carregamento.  
  
 Para exportar sua classe inteira, use **AFX\_EXT\_CLASS** na definição da classe.  Esta macro é definido pela estrutura como **\_\_declspec\(dllexport\)** quando **\_AFXDLL** e `_AFXEXT` são definidos, mas definido como **\_\_declspec\(dllimport\)** quando `_AFXEXT` não é definido.  `_AFXEXT` como descrito acima, é definido apenas ao criar seu DLL da extensão.  Por exemplo:  
  
```  
class AFX_EXT_CLASS CExampleExport : public CObject  
{ ... class definition ... };  
```  
  
### Não exportando a classe inteira  
 Às vezes você queira exportar apenas os membros necessários individuais da classe.  Por exemplo, se você estiver exportando `CDialog`\- classe derivada, você pode apenas precisar exportar o construtor e a chamada de `DoModal` .  Você pode exportar esses membros que usam o arquivo de .DEF da DLL, mas você também pode usar **AFX\_EXT\_CLASS** da mesma maneira nos membros individuais que você precisa exportar.  
  
 Por exemplo:  
  
```  
class CExampleDialog : public CDialog  
{  
public:  
   AFX_EXT_CLASS CExampleDialog();  
   AFX_EXT_CLASS int DoModal();  
   // rest of class definition  
   .  
   .  
   .  
};  
```  
  
 Quando você fizer isso, você pode executar em um problema adicional porque você não estiver exportando todos os membros da classe.  O problema está no modo como macros de MFC funcionam.  Vários macros de auxiliar MFC realmente declaram ou define os membros de dados.  Consequentemente, esses membros de dados também precisarão ser exportado do DLL.  
  
 Por exemplo, a macro de `DECLARE_DYNAMIC` é definido da seguinte maneira para criar uma DLL da extensão:  
  
```  
#define DECLARE_DYNAMIC(class_name) \  
protected: \  
   static CRuntimeClass* PASCAL _GetBaseClass(); \  
   public: \  
   static AFX_DATA CRuntimeClass class##class_name; \  
   virtual CRuntimeClass* GetRuntimeClass() const; \  
```  
  
 A linha que inicia “ `AFX_DATA`estático” está declarando um objeto estática dentro da classe.  Para exportar corretamente essa classe e acessar informações de tempo de execução de um cliente .EXE, você precisa exportar este objeto estático.  Como o objeto estático é declarado com o modificador `AFX_DATA`, você só precisa definir `AFX_DATA` para ser **\_\_declspec\(dllexport\)** ao criar seu DLL e define\-o como **\_\_declspec\(dllimport\)** durante a criação do executável do cliente.  
  
 Como discutido acima, **AFX\_EXT\_CLASS** já está definido dessa maneira.  Você precisa apenas de redefinir `AFX_DATA` para ser o mesmo que **AFX\_EXT\_CLASS** em torno da definição da classe.  
  
 Por exemplo:  
  
```  
#undef  AFX_DATA  
#define AFX_DATA AFX_EXT_CLASS  
class CExampleView : public CView  
{  
  DECLARE_DYNAMIC()  
  // ... class definition ...  
};  
#undef  AFX_DATA  
#define AFX_DATA  
```  
  
 O MFC sempre usa o símbolo de `AFX_DATA` em itens de dados que define dentro de seus macros, essa técnica funcionará para todos esses cenários.  Por exemplo, funcionará para `DECLARE_MESSAGE_MAP`.  
  
> [!NOTE]
>  Se você estiver exportando a classe inteira em vez de membros selecionados da classe, os membros de dados estáticos são exportados automaticamente.  
  
 Você pode usar a mesma técnica exportar automaticamente o operador de extração de `CArchive` para classes que usam macros de `DECLARE_SERIAL` e de `IMPLEMENT_SERIAL` .  Exportar o operador de arquivo morto que as declarações da classe \(localizadas em. Arquivo de H\) pelo seguinte código:  
  
```  
#undef AFX_API  
#define AFX_API AFX_EXT_CLASS  
  
<your class declarations here>  
  
#undef AFX_API  
#define AFX_API  
```  
  
### Limitações de \_AFXEXT  
 Você pode usar o símbolo do processador de**AFXEXT** \_para seus dlls da extensão conforme você não tiver várias camadas de DLL da extensão.  Se você tiver as dlls de extensão que chamam ou derivam das classes em seus próprios DLL de extensão, que deriva das classes em MFC, você deve usar seu próprio símbolo de pré\-processador para evitar a ambiguidade.  
  
 O problema é aquela no Win32, você deve declarar explicitamente todos os dados como **\_\_declspec\(dllexport\)** se deve ser exportado de uma DLL, e **\_\_declspec\(dllimport\)** se deve ser importado de uma DLL.  Quando você define `_AFXEXT`, os cabeçalhos de MFC ter certeza de que **AFX\_EXT\_CLASS** está definida corretamente.  
  
 Quando você tiver várias camadas, um símbolo como **AFX\_EXT\_CLASS** não é suficiente, desde que uma DLL de extensão pode exportar novas classes bem como importar outras classes de outro DLL da extensão.  Para tratar esse problema, use um símbolo de pré\-processador especial que indica que você está criando a DLL próprio em relação à utilização da DLL.  Por exemplo, imagine dois DLL de extensão, A.DLL, e B.DLL.  Eles cada exportação algumas classes na.H e em B.H, respectivamente.  B.DLL usa as classes da.DLL.  Os arquivos de cabeçalho olhariam aparência:  
  
```  
/* A.H */  
#ifdef A_IMPL  
   #define CLASS_DECL_A   __declspec(dllexport)  
#else  
   #define CLASS_DECL_A   __declspec(dllimport)  
#endif  
  
class CLASS_DECL_A CExampleA : public CObject  
{ ... class definition ... };  
  
/* B.H */  
#ifdef B_IMPL  
   #define CLASS_DECL_B   __declspec(dllexport)  
#else  
   #define CLASS_DECL_B   __declspec(dllimport)  
#endif  
  
class CLASS_DECL_B CExampleB : public CExampleA  
{ ... class definition .. };  
```  
  
 Quando A.DLL é criado, ele é compilado com **\/D A\_IMPL** e quando B.DLL é criado, é criado com **\/D B\_IMPL**.  Usando símbolos separados para cada DLL, CExampleB é exportado e CExampleA é importado para criar B.DLL.  CExampleA é exportado para criar A.DLL e importado quando usado por B.DLL \(ou por outro cliente\).  
  
 Esse tipo de estratificação não pode ser feito ao usar **AFX\_EXT\_CLASS** e símbolos internos de pré\-processador de `_AFXEXT` .  A técnica descrita acima resolve o problema de um modo não diferentemente dos usos MFC do próprio mecanismo para criar seus dlls de extensão de OLE, da base de dados, e de rede.  
  
### Não exportando a classe inteira  
 Além disso, você terá que executar especial quando você não estiver exportando uma classe inteira.  Você precisa garantir que os itens de dados necessários criados por macros de MFC são exportados corretamente.  Isso pode ser feito redefinindo **AFX\_DATA** a macro de suas classes específicas.  Isso deve ser feito quando você não estiver exportando a classe inteira.  
  
 Por exemplo:  
  
```  
// A.H  
#ifdef A_IMPL  
   #define CLASS_DECL_A  _declspec(dllexport)  
#else  
   #define CLASS_DECL_A  _declspec(dllimport)  
   #endif  
  
#undef  AFX_DATA  
#define AFX_DATA CLASS_DECL_A  
  
class CExampleA : public CObject  
{  
   DECLARE_DYNAMIC()  
   CLASS_DECL_A int SomeFunction();  
   //class definition   
   .  
   .  
   .  
};  
  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
### DllMain  
 O seguinte exemplo é o código exato é necessário colocar no arquivo de origem principal para o DLL da extensão.  Deve vir depois que o padrão inclui.  Observe que quando você usar AppWizard para criar arquivos do acionador de partida para uma DLL da extensão, fornece `DllMain` para você.  
  
```  
#include "afxdllx.h"  
  
static AFX_EXTENSION_MODULE extensionDLL;  
  
extern "C" int APIENTRY   
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)  
{  
   if (dwReason == DLL_PROCESS_ATTACH)  
   {  
      // Extension DLL one-time initialization   
      if (!AfxInitExtensionModule(  
             extensionDLL, hInstance))  
         return 0;  
  
      // TODO: perform other initialization tasks here  
   }  
   else if (dwReason == DLL_PROCESS_DETACH)  
   {  
      // Extension DLL per-process termination  
      AfxTermExtensionModule(extensionDLL);  
  
          // TODO: perform other cleanup tasks here  
   }  
   return 1;   // ok  
}  
```  
  
 A chamada para `AfxInitExtensionModule` captura as classes em tempo de compilação dos módulos \(estruturas de`CRuntimeClass` \) bem como suas fábricas de objeto \(objetos de`COleObjectFactory` \) para uso posterior quando o objeto de **CDynLinkLibrary** é criado.  O \(opcional\) chame a `AfxTermExtensionModule` permite a MFC a limpeza a DLL de extensão quando cada processo \(desanexar que acontece quando o processo é encerrado, ou quando a DLL é descarregado no resultado de uma chamada de **FreeLibrary** \) DLL da extensão.  Desde que a maioria de DLL de extensão não são carregados dinamicamente \(normalmente, são vinculados por meio das bibliotecas de importação\), a chamada para `AfxTermExtensionModule` geralmente não é necessário.  
  
 Se seu aplicativo carrega e libera DLL de extensão dinamicamente, certifique\-se de chamar `AfxTermExtensionModule` como mostrado acima.  Também certifique\-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` \(em vez do Win32 funcionam **LoadLibrary** e **FreeLibrary**\) se seu aplicativo usa vários threads ou se carrega dinamicamente uma DLL da extensão.  Usar `AfxLoadLibrary` e `AfxFreeLibrary` garante que a inicialização e o desligamento código que executa a DLL de extensão é carregado e descarregado não compromete o estado global de MFC.  
  
 O arquivo de cabeçalho AFXDLLX.H contém definições especiais para as estruturas usadas na DLL da extensão, como a definição de `AFX_EXTENSION_MODULE` e **CDynLinkLibrary**.  
  
 *O extensionDLL* global deve ser declarado como mostrado.  Ao contrário da versão de 16 bits de MFC, você pode alocar memória e chamar funções de MFC durante esse tempo, desde que o MFCxx.DLL é totalmente inicializado antes do `DllMain` é chamado.  
  
### Compartilhando recursos e classes  
 Dlls simples de extensão MFC só precisam exportar mais algumas funções de largura da banda baixa ao aplicativo cliente e a nada.  DLL mais intensivos da interface do usuário podem desejar exportar recursos e classes C\+\+ ao aplicativo cliente.  
  
 Exportar recursos é feito por meio de uma lista de recursos.  Em cada aplicativo é uma única vinculada lista de objetos de **CDynLinkLibrary** .  Ao procurar um recurso, a maioria das implementações de MFC padrão que carregam recursos e verifique primeiro no módulo atual de recursos \(\) e`AfxGetResourceHandle`caso não seja localizado\) a exames que a lista de objetos **CDynLinkLibrary** a tentativa de carregar o recurso solicitado.  
  
 A criação de objetos dinâmico de dados C\+\+ o nome da classe c é semelhante. criando  O mecanismo de desserialização do objeto de MFC precisa ter todos os objetos de `CRuntimeClass` registrados de modo que possa recriar dinamicamente criando o objeto do C\+\+ de tipo necessário com base no que foi anteriormente armazenado.  
  
 Se você quiser que o aplicativo cliente usar as classes em seu DLL de extensão que são `DECLARE_SERIAL`, você precisará exportar suas classes para ficar visível para o aplicativo cliente.  Isso é feito também examinando a lista de **CDynLinkLibrary** .  
  
 No caso dos conceitos avançados MFC [DLLHUSK](../top/visual-cpp-samples.md)de exemplo, a lista examina algo como:  
  
```  
head ->   DLLHUSK.EXE   - or -   DLLHUSK.EXE  
               |                      |  
          TESTDLL2.DLL           TESTDLL2.DLL  
               |                      |  
          TESTDLL1.DLL           TESTDLL1.DLL  
               |                      |  
               |                      |  
            MFC90D.DLL            MFC90.DLL  
```  
  
 O MFCxx.DLL é geralmente o mais recente na lista de recursos e da classe.  MFCxx.DLL inclui todos os recursos de MFC padrão, incluindo cadeias de caracteres alertas para todas as IDs padrão do comando.  Colocá\-lo no final da lista permite que a DLL e o aplicativo cliente em si não ter sua própria cópia dos recursos de MFC padrão, mas em vez de confiar em recursos compartilhados no MFCxx.DLL.  
  
 Mesclar os recursos e os nomes da classe de todas as dlls no espaço de nome de aplicativo cliente tem a desvantagem que você tem que ter cuidado para que as IDs ou nomes de sua escolha.  Você não pode desabilitar esse recurso não exportando os recursos ou um objeto de **CDynLinkLibrary** ao aplicativo cliente.  O exemplo de [DLLHUSK](../top/visual-cpp-samples.md) gerencia o espaço de nome compartilhado de recursos usando vários arquivos de cabeçalho.  Consulte [Observação 35 técnica](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md) para obter mais dicas sobre como usar arquivos de recursos compartilhados.  
  
### Inicializando o DLL  
 Como mencionado acima, você normalmente para criar um objeto de **CDynLinkLibrary** para exportar seus recursos e classes para o aplicativo cliente.  Você precisará fornecer um ponto de entrada exportado para inicializar a DLL.  Minimamente, essa é uma rotina vaga que não leve argumentos e não retorna nada, mas pode ser qualquer coisa que você gostaria.  
  
 Cada aplicativo cliente que deseja usar o DLL deve chamar esta rotina de inicialização, se você usar essa abordagem.  Você também pode atribuir esse objeto de **CDynLinkLibrary** em seu `DllMain` imediatamente depois de chamar `AfxInitExtensionModule`.  
  
 A rotina de inicialização deve criar um objeto de **CDynLinkLibrary** no heap de aplicativo atual, prendido até sua informações da DLL da extensão.  Isso pode ser feito com o seguinte:  
  
```  
extern "C" extern void WINAPI InitXxxDLL()  
{  
   new CDynLinkLibrary(extensionDLL);  
}  
```  
  
 O nome rotina, *InitXxxDLL* neste exemplo, pode ser qualquer nome desejado.  Não precisa ser `extern "C"`, mas fazer isso facilita a lista de exportação manter.  
  
> [!NOTE]
>  Se você usar seu DLL da extensão de uma DLL normal, você deverá exportar esta função de inicialização.  Essa função deve ser chamada DLL normal antes de usar qualquer classe ou recurso DLL da extensão.  
  
### Exportando entradas  
 A maneira simples de exportar suas classes é usar **\_\_declspec\(dllimport\)** e **\_\_declspec\(dllexport\)** em cada classe e global função que você deseja exportar.  Isso facilita\-a muito, mas é\-o menos eficiente do que nomeando cada ponto de entrada \(descrito abaixo\) desde que você tem menos controle sobre funções que são exportadas e você não poderá exportar as funções por ordinal.  TESTDLL1 e TESTDLL2 usam esse método para exportar suas entradas.  
  
 Um método mais eficaz \(e o método usado por MFCxx.DLL\) são exportar a mão cada entrada nomeando cada entrada no arquivo de .DEF.  Desde que nós estamos exportando exporta seletivas de nosso DLL \(isto é, não todos\), devemos decidir que interfaces de detalhes desejamos exportar.  Isso é difícil desde que você deve especificar os nomes massacrados ao vinculador na forma de entradas no arquivo de .DEF.  Não exportar nenhuma classes C\+\+ a menos que você precise fato de haver um link deles.  
  
 Se você tentasse exportando C\+\+ as classes com um .DEF arquivo antes, você pode desejar desenvolver uma ferramenta para gerar automaticamente essa lista.  Isso pode ser feito usando um processo de link de dois estágios.  Vincular seu DLL uma vez sem exportações, e permitem que o vinculador gerencia um arquivo de .MAP.  O arquivo de .MAP pode ser usado para gerar uma lista de funções que devem ser exportadas, o que com qualquer reorganizar, pode ser usado para gerar suas entradas EXPORT para o arquivo de .DEF.  A lista de exportação para MFCxx.DLL e OLE e as dlls de extensão da base de dados do, vários mil em número, foram gerados com esse processo \(embora não é completamente automático e não requer algumas mão que se ajusta de vez em quando\).  
  
### CWinApp em CDynLinkLibrary  
 Uma DLL da extensão MFC não tem `CWinApp`\- objeto derivado de seus próprios; em vez disso deve trabalhar com `CWinApp`\- objeto derivado do aplicativo cliente.  Isso significa que o aplicativo cliente possui a bomba principal da mensagem, o loop ocioso e assim por diante.  
  
 Se seu DLL de extensão MFC deve manter dados adicionais para cada aplicativo, você pode derivar uma nova classe de **CDynLinkLibrary** e criar na rotina de InitXxxDLL descreve acima.  Ao executar, a DLL pode verificar a lista atual do aplicativo de objetos de **CDynLinkLibrary** para localizar o para que o DLL específico de extensão.  
  
### Usando recursos em sua implementação da DLL  
 Como mencionado acima, a carga padrão de recursos andará a lista de objetos de **CDynLinkLibrary** que procuram o primeiro EXE ou DLL que tem o recurso solicitado.  Todos os APIs de MFC bem como todos os usos `AfxFindResourceHandle` de código interno percorrer a lista de recursos para localizar algum recurso, independentemente de onde pode residir.  
  
 Se você deseja carregar apenas os recursos de um local específico, use as APIs `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o identificador antigo e para definir a novo identificador.  Restaure todo o identificador antigo de recursos antes que você retorna ao aplicativo cliente.  O exemplo TESTDLL2 usar esta abordagem explicitamente carregando um menu.  
  
 Percorrer a lista tem as desvantagens que é ligeiramente mais lento e requer gerenciar intervalos de ID de recurso.  Tem a vantagem de um aplicativo cliente que vincula a vários DLL de extensão pode usar qualquer DLL\- forneceu o recurso sem ter que especifique o identificador de instância da DLL.  é usado`AfxFindResourceHandle` API examinando a lista de recursos para procurar uma correspondência determinada.  Tem o nome e o tipo de um recurso e retorna o identificador de recurso em que foi encontrada pela primeira vez \(ou NULL\).  
  
##  <a name="_mfcnotes_writing_an_application_that_uses_the_dll_version"></a> Escrevendo um aplicativo que usa a versão da DLL  
  
### Requisitos de aplicativo  
 Um aplicativo que usa a versão compartilhada MFC deve seguir algumas regras simples:  
  
-   Deve ter um objeto de `CWinApp` e para seguir o padrão as regras para uma mensagem bombeiam.  
  
-   Deve ser criada com um conjunto de sinalizadores necessários do compilador \(consulte abaixo\).  
  
-   Deve ser vinculado com as bibliotecas de importação de MFCxx.  Definindo sinalizadores necessários do compilador, os cabeçalhos de MFC determinam no tempo de link que a biblioteca o aplicativo deve vincular a.  
  
-   Para executar o executável, MFCxx.DLL deve estar no caminho ou no diretório do sistema do windows.  
  
### Compile com o ambiente de desenvolvimento  
 Se você estiver usando o makefile interno com que a maioria das opções padrão, você pode alterar facilmente o projeto criar a versão da DLL.  
  
 A seguinte etapa supõe que você tenha um aplicativo corretamente de operação MFC vinculado com NAFXCWD.LIB \(para a depuração\) e NAFXCW.LIB \(para o varejo\) e você deseja converter o para usar a versão compartilhada de biblioteca MFC.  Você está executando o ambiente do Visual C\+\+ e tem um arquivo de projeto interno.  
  
1.  No menu de **Projetos** , clique em **Propriedades**.  Na página de **Geral** em **Padrões do Projeto**, defina classes do Microsoft a **Usar MFC em uma DLL Compartilhada** \(MFCxx \(d\) .dll\).  
  
### Compile com NMAKE  
 Se você estiver usando o recurso externo do makefile do Visual C\+\+, ou está usando NMAKE diretamente, será necessário editar seu makefile para dar suporte a opções do compilador e do vinculador  
  
 Sinalizadores necessários do compilador:  
  
 **\/D\_AFXDLL \/MD**  
 **\/D\_AFXDLL**  
  
 Os cabeçalhos de MFC padrão desse símbolo precisam ser definidos:  
  
 **\/MD**  
 O aplicativo deve usar a versão da DLL da biblioteca de tempo de execução C  
  
 Todos os sinalizadores restantes do compilador seguem as opções de MFC \(por exemplo, \_DEBUG para a depuração\).  
  
 Editar a lista do vinculador de bibliotecas.  Alterar NAFXCWD.LIB a MFCxxD.LIB e modificar NAFXCW.LIB a MFCxx.LIB.  Substituir LIBC.LIB com o MSVCRT.LIB.  Como com qualquer outra biblioteca MFC é importante que MFCxxD.LIB é colocado **before** as bibliotecas do C \- tempo de execução.  
  
 Se desejar adicionar **\/D\_AFXDLL** ao varejo e depurar as opções do compilador de recursos \(aquela que realmente cria os recursos com **\/R**\).  Isso torna o menor executável final compartilhando os recursos que estão presentes na DLL MFC.  
  
 Uma recriação completa é necessária depois que essas alterações são feitas.  
  
### Criando Exemplos  
 A maioria dos programas de exemplo MFC podem ser criados do Visual C\+\+ ou de um MAKEFILE NMAKE\- compatível compartilhado da linha de comando.  
  
 Para converter qualquer um desses exemplos de uso de MFCxx.DLL, você pode carregar o arquivo de .MAK no Visual C\+\+ e definir as opções de projeto como descrito acima.  Se você estiver usando a construção de NMAKE, você pode especificar “AFXDLL\=1” na linha de comando de NMAKE e que criará o exemplo usando bibliotecas compartilhadas MFC.  
  
 Os conceitos avançados MFC [DLLHUSK](../top/visual-cpp-samples.md) de exemplo são criados com a versão da DLL MFC.  Este exemplo ilustra não apenas como criar um aplicativo vinculado com MFCxx.DLL, mas ilustra também outros recursos da DLL MFC qual pacote a opção como DLL de extensão MFC descritos posteriormente nesta técnica. observação  
  
### Empacotando notas  
 A versão de varejo da DLL \(MFCxx U \[\] .DLL\) é livremente redistribuível.  A versão de depuração de DLL não é redistribuível livremente e deve ser usada somente durante o desenvolvimento do aplicativo.  
  
 Dlls de depuração são fornecidos com as informações de depuração.  Usando o depurador do Visual C\+\+, você pode rastrear a execução do aplicativo bem como da DLL.  Dlls de versão \(MFCxx .DLL U \[\]\) não contêm informações de depuração.  
  
 Se você personaliza ou recria as dlls, você deve chamar algo diferente de “MFCxx” que o arquivo MFCDLL.MAK MFC SRC descreve as opções de compilação e a lógica para renomear a DLL.  Renomear os arquivos é necessário, pois esses DLL são compartilhados potencial por muitos aplicativos MFC.  Tendo sua versão personalizada de DLL MFC substituir esses instalados no sistema pode interromper outro aplicativo MFC usando as dlls compartilhados MFC.  
  
 Recriar as dlls de MFC não é recomendado.  
  
##  <a name="_mfcnotes_how_the_mfc30.dll_is_implemented"></a> O é implementado como MFCxx.DLL  
 A seção a seguir descreve como a DLL \(MFC MFCxx.DLL e MFCxxD.DLL\) é implementado.  Compreendendo os detalhes aqui também não são importantes se tudo o que você deseja fazer é usar o DLL MFC com seu aplicativo.  Os detalhes aqui não são essenciais para entender como escrever uma DLL da extensão MFC, mas entender essa implementação pode ajudar a escrever seu próprio DLL.  
  
### Visão geral de implementação  
 A DLL de MFC é realmente um caso especial de uma DLL da extensão MFC conforme descrito acima.  Tem um número muito grande de exportações para um grande número de classes.  Há algumas coisas que faça nós adicionais na DLL MFC que o tornam mais ainda especial de que uma DLL normal de extensão.  
  
### O Win32 faz a maioria do trabalho  
 A versão de 16 bits de MFC necessárias para um número de técnicas especiais que incluam dados do aplicativo no segmento da pilha, em segmentos especiais criados pelo código de assembly 80x86, em alguns contextos de exceção do processo, e em outras técnicas.  O Win32 suporte direto a dados do processo em uma DLL, que é o que você deseja na maioria das vezes.  Geralmente MFCxx.DLL é apenas NAFXCW.LIB empacotados em uma DLL.  Se você examina o código\-fonte MFC, você encontrará muito pouco o \_AFXDLL de \#ifdef, desde que houver poucos casos especiais que precisam ser feitas.  Os casos especiais que estão há manipular especificamente o Win32 no Windows 3.1 \(se não conhecido como Win32s\).  Win32s não oferece suporte a dados da DLL do processo diretamente para que o DLL MFC deve usar as APIs do Win32 \(TLS\) de armazenamento de thread local para obter dados do local do processo.  
  
### Impacto em fontes de biblioteca, arquivos adicionais  
 O impacto da versão de **\_AFXDLL** de fontes e em cabeçalhos comuns da biblioteca de classes de MFC é relativamente menor.  Há um arquivo especial de versão \(AFXV\_DLL.H\) e também um arquivo de cabeçalho adicional \(\) AFXDLL\_.H incluído pelo cabeçalho principal de AFXWIN.H.  O cabeçalho de AFXDLL\_.H contém a classe de **CDynLinkLibrary** e outros detalhes de implementação de aplicativos de **\_AFXDLL** e de DLL de extensão MFC.  O cabeçalho de AFXDLLX.H é fornecido para criar DLL de extensão MFC \(consulte acima para obter detalhes\).  
  
 As fontes regulares à biblioteca MFC MFC em SRC têm algum código condicional adicional no \#ifdef de **\_AFXDLL** .  Um arquivo de origem extra \(\) DLLINIT.CPP contém o código de inicialização adicional da DLL e a outra cola para a versão compartilhada MFC.  
  
 Para criar a versão compartilhada MFC, os arquivos adicionais são fornecidas. \(Consulte abaixo para obter detalhes sobre como compilar a DLL.\)  
  
-   Dois arquivos de .DEF são usados exportando os pontos de entrada DLL MFC para a depuração \(MFCxxD.DEF\) e liberam as versões \(MFCxx.DEF\) da DLL.  
  
-   Um arquivo de .RC \(MFCDLL.RC\) contém todos os recursos de MFC padrão e um recurso de VERSIONINFO para a DLL.  
  
-   Um arquivo de .CLW \(MFCDLL.CLW\) é fornecido para permitir procurar as classes de MFC usando ClassWizard.  Observação: esse recurso não é específico a versão da DLL MFC.  
  
### Gerenciamento de memória  
 Um aplicativo que usa MFCxx.DLL usa um alocador comuns fornecido por MSVCRTxx.DLL, a DLL de memória compartilhada do C \- tempo de execução.  O aplicativo, todas as dlls de extensão e, bem como os próprios DLL MFC usa esse alocador de memória compartilhada.  Usando uma DLL compartilhado para alocação de memória, as dlls de MFC podem atribuir a memória que é liberada depois pelo aplicativo ou vice\-versa.  Como o aplicativo e o DLL devem usar o mesmo alocador, você não deve substituir o C\+\+ `operator new` global ou `operator delete`.  As mesmas regras se aplicam ao resto de rotinas de alocação de memória de tempo de execução C \(como `malloc`, `realloc`, **free**, entre outros\).  
  
### Ordinais da classe e \_\_declspec \(dllexport\) e nomenclatura da DLL  
 Nós não usar a funcionalidade de `class`**\_\_declspec\(dllexport\)** do compilador C\+\+.  Em vez disso, uma lista de exportações é incluída nas origens de biblioteca de classe \(MFCxx.DEF e MFCxxD.DEF\).  Esse é o conjunto selecionado de pontos de entrada \(funções e dados\) é exportado somente.  Outros símbolos, como funções ou classes privadas de implementação de MFC, não são exportados todas as exporta são feitas pelo ordinal sem um nome de cadeia de caracteres em ou residente na tabela não residente do nome.  
  
 Usar `class` **\_\_declspec\(dllexport\)** pode ser uma alternativa viável para criar DLL menores, mas no caso de um grande DLL como o MFC, o mecanismo exportando padrão tem limites da eficiência e a possibilidade de.  
  
 O que esse todos significa que podemos pacote uma grande quantidade de funcionalidade na versão MFCxx.DLL que é somente em torno de 800 KB sem comprometer muitas execução ou carregar a velocidade.  MFCxx.DLL seria 100K maior essa técnica não tivesse sido usado.  Isso também é possível adicionar pontos de entrada adicional no final de .DEF para arquivar para permitir o controle de versão simples sem comprometer a eficiência da velocidade e do tamanho de exportar por ordinal.  As revisões de versão principal na biblioteca de classes de MFC alterará o nome da biblioteca.  Isto é, MFC30.DLL é redistribuível a DLL que contém a versão 3,0 da biblioteca MFC da classe.  Uma atualização deste DLL por exemplo em um MFC\) 3,1, a DLL será denominada MFC31.DLL em vez disso.  Além disso, se você alterar o código\-fonte MFC para gerar uma versão personalizado DLL MFC, use um nome diferente \(preferivelmente e um sem “MFC” no nome\).  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)