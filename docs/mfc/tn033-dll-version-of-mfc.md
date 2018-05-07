---
title: 'TN033: Versão DLL do MFC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.dll
dev_langs:
- C++
helpviewer_keywords:
- MFC DLLs [MFC], writing MFC extension DLLS
- AFXDLL library
- DLLs [MFC], MFC
- DLL version of MFC [MFC]
- TN033
ms.assetid: b6f1080b-b66b-4b1e-8fb1-926c5816392c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a247ffc36b3e0eb3e52c6f04949c693597d73064
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tn033-dll-version-of-mfc"></a>TN033: versão DLL do MFC
Esta anotação descreve como você pode usar o MFCxx.DLL e MFCxxD.DLL (onde x é o número de versão do MFC) compartilhado bibliotecas de vínculo dinâmico com aplicativos MFC e DLLs de extensão do MFC. Para obter mais informações sobre DLLs normais do MFC, consulte [usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md).  
  
 Essa observação técnica abrange três aspectos de DLLs. Os dois últimos são para os usuários mais avançados:  
  
- [Como criar uma DLL de extensão do MFC](#_mfcnotes_how_to_write_an_mfc_extension_dll)  
  
- [Como criar um aplicativo MFC que usa a versão DLL do MFC](#_mfcnotes_writing_an_application_that_uses_the_dll_version)  
  
- [Como o MFC compartilhado bibliotecas de vínculo dinâmico são implementados](#_mfcnotes_how_the_mfc30.dll_is_implemented)  
  
 Se você estiver interessado na criação de uma DLL usando MFC que pode ser usado com aplicativos não MFC (Isso é chamado uma DLL MFC regular), consulte [11 de observação técnica](../mfc/tn011-using-mfc-as-part-of-a-dll.md).  
  
## <a name="overview-of-mfcxxdll-support-terminology-and-files"></a>Visão geral de suporte de MFCxx.DLL: arquivos e terminologia  
 **DLL MFC regular**: você usa uma DLL MFC regular para compilar uma DLL autônoma usando algumas das classes MFC. Interfaces através do limite de aplicativo/DLL são interfaces de "C", e o aplicativo cliente não precisa ser um aplicativo do MFC.  
  
 Essa é a versão de DLL suporte com suporte no MFC 1.0. Ela é descrita [11 de observação técnica](../mfc/tn011-using-mfc-as-part-of-a-dll.md) o exemplo de conceitos avançados do MFC e [DLLScreenCap](../visual-cpp-samples.md).  
  
> [!NOTE]
>  A partir do Visual C++ versão 4.0, o termo **USRDLL** está obsoleta e foi substituída por uma DLL MFC regular que se vincula estaticamente ao MFC. Você também pode criar uma DLL do MFC que vincula dinamicamente a MFC regular.  
  
 MFC 3.0 (ou superior) dá suporte a DLLs normais do MFC com todas as novas funcionalidades incluindo as classes OLE e o banco de dados.  
  
 **AFXDLL**: isso é também conhecido como a versão compartilhada das bibliotecas MFC. Este é o novo suporte a DLL adicionado no MFC 2.0. A biblioteca do MFC está em um número de DLLs (descritas abaixo) e um aplicativo cliente ou a DLL vincula dinamicamente as DLLs que ele exige. Interfaces através do limite de aplicativo/DLL são C + + interfaces de classe do MFC. O aplicativo cliente deve ser um aplicativo do MFC. Isso dá suporte a todas as funcionalidades do MFC 3.0 (exceção: não há suporte para UNICODE para as classes de banco de dados).  
  
> [!NOTE]
>  A partir do Visual C++ versão 4.0, esse tipo de DLL é conhecido como "Extensão DLL."  
  
 Esta anotação usará MFCxx.DLL para se referir a todo o conjunto de DLL MFC, que inclui:  
  
-   Depuração: MFCxxD.DLL (combinados) e MFCSxxD.LIB (estático).  
  
-   Versão: MFCxx.DLL (combinados) e MFCSxx.LIB (estático).  
  
-   Depuração de Unicode: MFCxxUD.DLL (combinados) e MFCSxxD.LIB (estático).  
  
-   Versão de Unicode: MFCxxU.DLL (combinados) e MFCSxxU.LIB (estático).  
  
> [!NOTE]
>  O MFCSxx [U] [D]. LIB bibliotecas são usadas em conjunto com o MFC compartilhado DLLs. Essas bibliotecas contêm código que deve ser vinculado estaticamente para o aplicativo ou DLL.  
  
 Bibliotecas de importação de um aplicativo é vinculado a correspondente:  
  
-   Depurar: MFCxxD.LIB  
  
-   Versão: MFCxx.LIB  
  
-   Depuração de Unicode: MFCxxUD.LIB  
  
-   Versão Unicode: MFCxxU.LIB  
  
 Uma DLL de extensão"MFC" é uma DLL baseada MFCxx.DLL (e/ou a outros MFC compartilhado DLLs). Aqui a arquitetura de componentes MFC é ativado. Se você deriva uma classe útil de uma classe do MFC ou criar outro Kit de ferramentas MFC semelhante, você pode colocá-lo em uma DLL. DLL usado MFCxx.DLL, assim como o aplicativo cliente ultimate. Isso permite que classes de folha reutilizável, reutilizáveis classes base e classes de exibição/documento reutilizáveis.  
  
## <a name="pros-and-cons"></a>Prós e contras  
 Por que você deve usar a versão compartilhada do MFC  
  
-   Usando a biblioteca compartilhada pode resultar em aplicativos menores (um aplicativo mínimo que usa a maior parte da biblioteca MFC é menos de 10K).  
  
-   Oferece suporte a versão compartilhada do MFC DLLs de extensão do MFC e DLLs normais do MFC.  
  
-   Criando um aplicativo que usa as bibliotecas MFC compartilhadas é mais rápido do que criar um aplicativo MFC vinculado estaticamente porque ele não é necessário vincular MFC em si. Isso é especialmente verdadeiro em **depurar** compilações em que o vinculador deve compactar as informações de depuração, por meio da vinculação com uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar dentro de seu aplicativo.  
  
 Por que você não usar a versão compartilhada do MFC:  
  
-   Um aplicativo que usa a biblioteca compartilhada de envio exige que você enviar o MFCxx.DLL (e outros) biblioteca com seu programa. MFCxx.DLL pode ser redistribuído como várias DLLs, mas você ainda deve instalar a DLL em seu programa de instalação. Além disso, você deve enviar MSVCRTxx.DLL, que contém a biblioteca de tempo de execução C que é usada pelo seu programa e as DLLs MFC próprios.  
  
##  <a name="_mfcnotes_how_to_write_an_mfc_extension_dll"></a> Como escrever uma DLL de extensão do MFC  
 Uma DLL de extensão do MFC é uma DLL que contém classes e funções escritas para aprimorar a funcionalidade das classes MFC. Uma DLL de extensão do MFC usa as MFC DLLs compartilhadas da mesma forma que um aplicativo usa, com algumas considerações adicionais:  
  
-   O processo de compilação é semelhante à criação de um aplicativo que usa as bibliotecas MFC compartilhadas com alguns compilador adicional e opções do vinculador.  
  
-   Uma DLL de extensão do MFC não tem um `CWinApp`-classe derivada.  
  
-   Uma DLL de extensão do MFC deve fornecer um especial `DllMain`. AppWizard fornece um `DllMain` função que você pode modificar.  
  
-   Uma DLL de extensão do MFC geralmente fornecem uma rotina de inicialização para criar um **CDynLinkLibrary** se a extensão MFC DLL desejar exportar `CRuntimeClass`es ou recursos para o aplicativo. Uma classe derivada de **CDynLinkLibrary** pode ser usado se os dados de aplicativo devem ser mantidos pela DLL de extensão do MFC.  
  
 Essas considerações são descritas em mais detalhes abaixo. Consulte também o exemplo de conceitos avançados do MFC [DLLHUSK](../visual-cpp-samples.md) desde que ele ilustra:  
  
-   Criando um aplicativo usando as bibliotecas compartilhadas. (DLLHUSK. EXE é um aplicativo MFC que vincula dinamicamente as bibliotecas MFC, bem como outras DLLs).  
  
-   Criar uma DLL de extensão do MFC. (Observe os sinalizadores especiais, como `_AFXEXT` que são usadas na criação de uma DLL de extensão do MFC)  
  
-   Dois exemplos de DLLs de extensão do MFC. Um mostra a estrutura básica de uma DLL de extensão do MFC com exportações limitadas (TESTDLL1) e outros mostra a exportação de uma interface de classe inteira (TESTDLL2).  
  
 O aplicativo cliente e qualquer DLLs de extensão do MFC devem usar a mesma versão do MFCxx.DLL. Você deve seguir a convenção de DLL MFC e fornecer dois debug e de varejo (/Release) versão do seu DLL de extensão do MFC. Isso permite que programas de cliente para criar versões de depuração e varejo de seus aplicativos e vinculá-los com a versão de varejo de todas as DLLs ou depuração apropriada.  
  
> [!NOTE]
>  Como C++ nome desconfiguração e exportar problemas, a lista de exportação de uma DLL de extensão do MFC pode ser diferente entre as versões de depuração e de varejo da mesma DLL e DLLs para diferentes plataformas. Varejo MFCxx.DLL sobre 2000 exportou pontos de entrada; a depuração MFCxxD.DLL 3000 sobre exportou pontos de entrada.  
  
### <a name="quick-note-on-memory-management"></a>Observação rápida sobre gerenciamento de memória  
 A seção "Gerenciamento de memória," próximo ao final desta nota técnica, descreve a implementação de MFCxx.DLL com a versão compartilhada do MFC. As informações que você precisa saber para implementar apenas uma extensão MFC que dll está descrito aqui.  
  
 MFCxx.DLL e todas as DLLs de extensão do MFC carregadas no espaço de endereço de um aplicativo cliente usarão o mesmo alocador de memória, carregamento de recursos e outros estados "globais" MFC como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas de DLL não - MFC e DLLs normais do MFC estaticamente vinculadas a MFC fazer o oposto exato e tem cada DLL alocando fora de seu próprio pool de memória.  
  
 Se uma DLL de extensão do MFC aloca memória, que a memória pode combinar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que usa as bibliotecas MFC compartilhadas falhar, a proteção do sistema operacional mantém a integridade de qualquer outro aplicativo do MFC a DLL de compartilhamento.  
  
 Da mesma forma outros estados MFC "globais", como o arquivo executável atual ao carregar recursos, também são compartilhados entre o aplicativo cliente e todas as DLLs de extensão do MFC, bem como MFCxx.DLL em si.  
  
### <a name="building-an-mfc-extension-dll"></a>Criar uma DLL de extensão do MFC  
 Você pode usar AppWizard para criar um projeto DLL de extensão do MFC e irá gerar automaticamente o compilador apropriado e as configurações do vinculador. Foi também gerar uma `DllMain` função que você pode modificar.  
  
 Se você estiver convertendo um projeto existente para uma DLL de extensão do MFC, inicie com as regras padrão para a criação de um aplicativo usando a versão compartilhada do MFC e faça o seguinte:  
  
-   Adicionar **/D_AFXEXT** aos sinalizadores de compilador. Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria de pré-processador. Adicionar `_AFXEXT` para o campo definir Macros, separando cada um dos itens com ponto e vírgula.  
  
-   Remover o **/Gy** opção de compilador. Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria de geração de código. Certifique-se de que a opção "Habilitar vínculo em nível de função" não está habilitada. Isso facilitará exportar classes porque o vinculador não removerá sem referência de funções. Se o projeto original é usado para criar uma expressão DLL MFC vinculado estaticamente ao MFC, alterar o **/MT [d]** opção de compilador para **/MD [d]**.  
  
-   Criar uma biblioteca de exportação com o **/DLL** opção de LINK. Isso será definido quando você cria um novo destino, especificando a biblioteca de vínculo dinâmico do Win32 como o tipo de destino.  
  
### <a name="changing-your-header-files"></a>Alterando os arquivos de cabeçalho  
 A meta de uma DLL de extensão do MFC normalmente é exportar algumas funcionalidades comuns para um ou mais aplicativos que podem usar essa funcionalidade. Isso se resume em Exportar classes e funções globais que estão disponíveis para aplicativos cliente.  
  
 Para fazer isso, você deve garantir que cada uma das funções de membro está marcada como importar ou exportar conforme apropriado. Isso requer declarações especiais: **dllexport** e **__declspec(dllimport)**. Quando as classes são usadas pelos aplicativos cliente, que eles devem ser declarados como **__declspec(dllimport)**. Quando a própria DLL de extensão do MFC está sendo compilado, eles devem ser declarados como **dllexport**. Além disso, as funções devem ser realmente exportadas, para que os programas cliente vinculá-las em tempo de carregamento.  
  
 Para exportar sua classe inteira, use **AFX_EXT_CLASS** na definição de classe. Essa macro é definida pela estrutura como **dllexport** quando **_AFXDLL** e `_AFXEXT` é definida, mas definida como **__declspec(dllimport)** quando `_AFXEXT` não está definido. `_AFXEXT` conforme descrito acima, é definido apenas quando estiver criando a DLL de extensão do MFC. Por exemplo:  
  
```  
class AFX_EXT_CLASS CExampleExport : public CObject  
{ ... class definition ... };  
```  
  
### <a name="not-exporting-the-entire-class"></a>Não exportar a classe inteira  
 Às vezes, você talvez queira exportar apenas os membros individuais necessários da sua classe. Por exemplo, se você estiver exportando um `CDialog`-derivado da classe, você só precisa exportar o construtor e o `DoModal` chamar. Você pode exportar esses membros usando o DLL. Arquivo de definição, mas você também pode usar **AFX_EXT_CLASS** da mesma forma em que os membros individuais, você precisa exportar.  
  
 Por exemplo:  
  
```  
class CExampleDialog : public CDialog  
{  
public:  
    AFX_EXT_CLASS CExampleDialog();
AFX_EXT_CLASS int DoModal();
*// rest of class definition  
 .  
 .  
 .  
};  
```  
  
 Quando você fizer isso, você pode encontrar um problema adicional porque você não está exportando todos os membros da classe. O problema é da forma que funcionam de macros MFC. Na verdade, várias das macros do auxiliar do MFC declaram ou definem membros de dados. Portanto, esses membros de dados também precisa ser exportados do seu DLL.  
  
 Por exemplo, o `DECLARE_DYNAMIC` macro é definida como a seguir ao criar uma DLL de extensão do MFC:  
  
```  
#define DECLARE_DYNAMIC(class_name) \  
protected: \  
    static CRuntimeClass* PASCAL _GetBaseClass();

\  
    public: \  
    static AFX_DATA CRuntimeClass class##class_name; \  
    virtual CRuntimeClass* GetRuntimeClass() const;

\  
```  
  
 A linha que começa "estático `AFX_DATA`" está declarando um objeto estático dentro de sua classe. Para exportar esta classe corretamente e acessar as informações de tempo de execução de um cliente. EXE, é necessário exportar este objeto estático. Porque o objeto estático é declarado com o modificador `AFX_DATA`, você precisa definir `AFX_DATA` ser **dllexport** ao criar a DLL e defini-lo como **__declspec(dllimport)** ao criar o executável do cliente.  
  
 Como discutido acima, **AFX_EXT_CLASS** já está definido dessa maneira. Você só precisa definir novamente `AFX_DATA` para ser o mesmo que **AFX_EXT_CLASS** em torno de sua definição de classe.  
  
 Por exemplo:  
  
```  
#undef  AFX_DATA  
#define AFX_DATA AFX_EXT_CLASS  
class CExampleView : public CView  
{  
    DECLARE_DYNAMIC() *// ... class definition ...  
};  
#undef  AFX_DATA  
#define AFX_DATA  
```  
  
 MFC sempre usa o `AFX_DATA` símbolo em itens de dados define em suas macros, portanto essa técnica funciona para todos esses cenários. Por exemplo, ele funciona para `DECLARE_MESSAGE_MAP`.  
  
> [!NOTE]
>  Se você estiver exportando a classe inteira em vez de membros selecionados da classe, membros de dados estáticos são exportados automaticamente.  
  
 Você pode usar a mesma técnica para exportar automaticamente o `CArchive` operador de extração para classes que usam o `DECLARE_SERIAL` e `IMPLEMENT_SERIAL` macros. Exporte o operador de arquivamento, colocar entre colchetes as declarações de classe (localizado em de. Arquivo H) com o código a seguir:  
  
```  
#undef AFX_API  
#define AFX_API AFX_EXT_CLASS  
 
<your class declarations here>  
 
#undef AFX_API  
#define AFX_API  
```  
  
### <a name="limitations-of-afxext"></a>Limitações de afxext  
 Você pode usar o _**AFXEXT** símbolo do pré-processador para sua extensão de MFC, desde que você não tem várias camadas de DLLs de extensão do MFC. Se você tiver a extensão de MFC que chame ou derivar de classes em sua própria extensão de MFC, que, em seguida, derivam as classes MFC, você deve usar seu próprio símbolo do pré-processador para evitar ambiguidade.  
  
 O problema é que Win32 no, você deve declarar explicitamente todos os dados como **dllexport** se é para ser exportada de uma DLL, e **__declspec(dllimport)** se ele será importado de uma DLL. Quando você define `_AFXEXT`, os cabeçalhos MFC Verifique se **AFX_EXT_CLASS** está definido corretamente.  
  
 Quando você tiver várias camadas, um símbolo, como **AFX_EXT_CLASS** não é suficiente, desde que uma DLL de extensão do MFC pode ser exportando novas classes, bem como importação outras classes do outro DLL de extensão do MFC. Para lidar com esse problema, use um símbolo do pré-processador especial que indica que você está criando a DLL em comparação a utilizar a DLL. Por exemplo, imagine duas DLLs de extensão do MFC,. dll e b. dll. Cada um deles exportar algumas classes em A.H e B.H, respectivamente. B. dll usa as classes do. dll. Os arquivos de cabeçalho deve ter esta aparência:  
  
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
  
 Quando é compilado. dll, que é compilado com **/D A_IMPL** e quando o b. dll é criado, ele é compilado com **/D B_IMPL**. Usando símbolos separados para cada DLL CExampleB é exportado e CExampleA é importado durante a criação de b. dll. CExampleA é exportado durante a criação. dll e importado quando usado por b. dll (ou outro cliente).  
  
 Esse tipo de camada não pode ser feito ao usar o interno **AFX_EXT_CLASS** e `_AFXEXT` símbolos de pré-processamento. A técnica descrita acima resolve esse problema de maneira diferente não que o mecanismo MFC em si usa ao criar suas DLLs de extensão OLE, banco de dados e rede MFC.  
  
### <a name="not-exporting-the-entire-class"></a>Não exportar a classe inteira  
 Novamente, você precisará tomar o cuidado quando você não estiver exportando toda uma classe. Você precisa garantir que os itens de dados necessários criados pelas macros MFC são exportados corretamente. Isso pode ser feito definindo novamente **AFX_DATA** macro de sua classe específica. Isso deve ser feito a qualquer momento, que não exportar a classe inteira.  
  
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
*//class definition   
 .  
 .  
 .  
};  
 
#undef AFX_DATA  
#define AFX_DATA  
```  
  
### <a name="dllmain"></a>DllMain  
 A seguir está o código exato que você deve colocar em seu arquivo de origem principal para a DLL de extensão do MFC. Ele deve vir após incluir o padrão. Observe que, quando você usar AppWizard para criar arquivos de início para uma DLL de extensão do MFC, ele fornece um `DllMain` para você.  
  
```  
#include "afxdllx.h"  
  
static AFX_EXTENSION_MODULE extensionDLL;  
  
extern "C" int APIENTRY   
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)  
{  
   if (dwReason == DLL_PROCESS_ATTACH)  
   {  
      // MFC extension DLL one-time initialization   
      if (!AfxInitExtensionModule(  
             extensionDLL, hInstance))  
         return 0;  
  
      // TODO: perform other initialization tasks here  
   }  
   else if (dwReason == DLL_PROCESS_DETACH)  
   {  
      // MFC extension DLL per-process termination  
      AfxTermExtensionModule(extensionDLL);  
  
          // TODO: perform other cleanup tasks here  
   }  
   return 1;   // ok  
}  
```  
  
 A chamada para `AfxInitExtensionModule` captura as classes de tempo de execução de módulos (`CRuntimeClass` estruturas), bem como as fábricas de seu objeto (`COleObjectFactory` objetos) para uso posteriormente, quando o **CDynLinkLibrary** objeto é criado. A chamada (opcional) para `AfxTermExtensionModule` permite MFC limpeza a DLL de extensão do MFC quando cada processo desanexa (que ocorre quando o processo foi encerrado, ou quando a DLL é descarregada como resultado de uma **FreeLibrary** chamar) da DLL de extensão de MFC . Desde que a maioria das DLLs não são carregadas dinamicamente de extensão do MFC (normalmente, eles são vinculados por meio de suas bibliotecas de importação), a chamada para `AfxTermExtensionModule` geralmente não é necessário.  
  
 Se seu aplicativo carrega e libera DLLs de extensão do MFC dinamicamente, certifique-se de chamar `AfxTermExtensionModule` como mostrado acima. Também Certifique-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez de funções do Win32 **LoadLibrary** e **FreeLibrary**) se seu aplicativo usa vários threads, ou se ele dinamicamente carrega um MFC DLL de extensão. Usando `AfxLoadLibrary` e `AfxFreeLibrary` assegura que o código de inicialização e desligamento que é executado quando a DLL de extensão do MFC é carregado e descarregado não corromper o estado global do MFC.  
  
 O arquivo de cabeçalho AFXDLLX. H contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a definição de `AFX_EXTENSION_MODULE` e **CDynLinkLibrary**.  
  
 Global *extensionDLL* devem ser declarados como mostrado. Ao contrário da versão de 16 bits de MFC, você pode alocar memória e chamar funções MFC durante esse tempo, desde que o MFCxx.DLL está totalmente inicializado pelo tempo seu `DllMain` é chamado.  
  
### <a name="sharing-resources-and-classes"></a>Compartilhamento de recursos e Classes  
 Simples DLLs de extensão do MFC só precisam exportar algumas funções de baixa largura de banda para o aplicativo cliente e nada mais. DLLs de uso intensivo de interface do usuário mais talvez queira exportar classes C++ e recursos para o aplicativo cliente.  
  
 Exportação de recursos é feita por meio de uma lista de recursos. Em cada aplicativo é uma lista individualmente vinculada de **CDynLinkLibrary** objetos. Ao procurar por um recurso, a maioria das implementações do MFC padrão que carregar recursos procuram primeira no módulo de recurso atual (`AfxGetResourceHandle`) e, se não encontrado walk a lista de **CDynLinkLibrary** objetos tentar carregar o recurso solicitado.  
  
 Criação dinâmica de objetos C++ recebe um nome de classe C++ é semelhante. O mecanismo de desserialização de objetos MFC precisa ter todos os `CRuntimeClass` objetos registrados para que ele pode reconstruir criando dinamicamente objeto C++ do tipo necessário com base no que foi armazenado anteriormente.  
  
 Se você quiser que o aplicativo cliente para usar as classes que estão em sua DLL de extensão do MFC `DECLARE_SERIAL`, em seguida, você precisará exportar suas classes para ficar visível para o aplicativo cliente. Isso também é feito inserindo o **CDynLinkLibrary** lista.  
  
 No caso do exemplo de conceitos avançados do MFC [DLLHUSK](../visual-cpp-samples.md), a lista tem a seguinte aparência:  
  
```  
head ->   DLLHUSK.EXE   - or -   DLLHUSK.EXE  
 |      |  
    TESTDLL2.DLL TESTDLL2.DLL  
 |      |  
    TESTDLL1.DLL TESTDLL1.DLL  
 |      |  
 |      |  
    MFC90D.DLL MFC90.DLL  
```  
  
 O MFCxx.DLL é geralmente último na lista de classes e recursos. MFCxx.DLL inclui todos os recursos padrão do MFC, inclusive cadeias de caracteres de prompt para todas as IDs de comando padrão. Colocá-lo ao final da lista permite DLLs e o aplicativo cliente em si não tenha um sua própria cópia dos recursos MFC padrão, mas ao confiar nos recursos compartilhados no MFCxx.DLL em vez disso.  
  
 Mesclando os recursos e os nomes de classe de todas as DLLs espaço para nome do aplicativo cliente tem a desvantagem de que você precisa tomar cuidado qual IDs ou nomes que você escolher. Você pode logicamente desabilitar esse recurso não exportando a seus recursos ou um **CDynLinkLibrary** objeto para o aplicativo cliente. O [DLLHUSK](../visual-cpp-samples.md) exemplo gerencia o espaço de nome de recurso compartilhado usando vários arquivos de cabeçalho. Consulte [35 de observação técnica](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md) para obter mais dicas sobre como usar arquivos de recurso compartilhado.  
  
### <a name="initializing-the-dll"></a>Inicializar a DLL  
 Conforme mencionado acima, você geralmente deseja criar um **CDynLinkLibrary** objeto para exportar seus recursos e classes para o aplicativo cliente. Você precisará fornecer um ponto de entrada exportado para inicializar a DLL. No mínimo, isso é uma rotina void que não requer argumentos e não retorna nada, mas pode ser qualquer coisa que você deseja.  
  
 Cada aplicativo de cliente que deseja usar sua DLL deve chamar a rotina de inicialização, se você usar essa abordagem. Isso também pode alocar **CDynLinkLibrary** do objeto em seu `DllMain` depois de chamar `AfxInitExtensionModule`.  
  
 A rotina de inicialização deve criar um **CDynLinkLibrary** objeto no heap do aplicativo atual, conectada a informações de DLL de extensão do MFC. Isso pode ser feito com o seguinte:  
  
```  
extern "C" extern void WINAPI InitXxxDLL()  
{  
    new CDynLinkLibrary(extensionDLL);

}  
```  
  
 O nome da rotineiro, *InitXxxDLL* neste exemplo, pode ser qualquer coisa que você deseja. Ele não precisa ser `extern "C"`, mas fazer assim torna mais fácil de manter a lista de exportação.  
  
> [!NOTE]
>  Se você usar a DLL de extensão do MFC de uma DLL MFC regular, você deve exportar esta função de inicialização. Essa função deve ser chamada de DLL MFC normal antes de usar qualquer classes DLL de extensão do MFC ou recursos.  
  
### <a name="exporting-entries"></a>Entradas de exportação  
 A maneira simple de exportar as classes é usar **__declspec(dllimport)** e **dllexport** em cada classe e a função global que você deseja exportar. Isso torna muito mais fácil, mas é menos eficiente do que a nomenclatura cada ponto de entrada (descrito abaixo), já que você tem menos controle sobre quais funções são exportadas e você não pode exportar as funções por ordinal. TESTDLL1 e TESTDLL2 usam esse método para exportar suas entradas.  
  
 Um método mais eficiente (e o método usado pelo MFCxx.DLL) é exportar cada entrada manualmente ao nomear cada entrada no. Arquivo de definição. Já que estamos estiver exportando seletivas exportações de nossa DLL (ou seja, nem tudo), podemos deve decidir quais interfaces específicos que deseja exportar. Isso é difícil porque você deve especificar os nomes danificados para o vinculador na forma de entradas na. Arquivo de definição. Não exporte todas as classes C++, a menos que você realmente precisa ter um link simbólico para ele.  
  
 Se você tentou exportar C++ classes com um. Definição de arquivo antes, talvez você queira desenvolver uma ferramenta para gerar essa lista automaticamente. Isso pode ser feito usando um processo de link de dois estágios. Vincular seu DLL uma vez com nenhuma exportação e permitir que o vinculador gerar um. Arquivo de mapa. A. Arquivo de mapa pode ser usado para gerar uma lista de funções que devem ser exportados para com alguns reorganizar, ele pode ser usado para gerar as entradas de exportação para o. Arquivo de definição. A lista de exportação de MFCxx.DLL OLE e DLLs de extensão do MFC de banco de dados, vários milhares em número, foi gerada com um processo (embora ela não é totalmente automática e requer alguns mão ajuste de vez em quando).  
  
### <a name="cwinapp-vs-cdynlinklibrary"></a>CWinApp vs. CDynLinkLibrary  
 Uma DLL de extensão do MFC não tem um `CWinApp`-objeto dele derivado; em vez disso, ele deve funcionar com o `CWinApp`-derivados do objeto do aplicativo cliente. Isso significa que o aplicativo cliente possui a bomba de mensagem principal, o loop ocioso e assim por diante.  
  
 Se a DLL de extensão do MFC precisa manter dados extras para cada aplicativo, você pode derivar uma nova classe de **CDynLinkLibrary** e crie-o a InitXxxDLL rotina descritas acima. Quando em execução, a DLL pode verificar a lista do aplicativo atual de **CDynLinkLibrary** objetos para localizar o item para essa extensão MFC DLL específico.  
  
### <a name="using-resources-in-your-dll-implementation"></a>Uso de recursos em sua implementação de DLL  
 Conforme mencionado acima, a carga de recurso padrão orientará a lista de **CDynLinkLibrary** objetos procurando primeiro EXE ou DLL que tem o recurso solicitado. Todas as APIs do MFC, bem como todo o código interno usa `AfxFindResourceHandle` para percorrer a lista de recursos para localizar qualquer recurso, não importa onde ele pode residir.  
  
 Se você deseja carregar apenas os recursos de um local específico, use as APIs `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o identificador antigo e definir o novo identificador. Certifique-se de restaurar o identificador de recurso antigo antes de retornar ao aplicativo cliente. O exemplo TESTDLL2 usa essa abordagem para carregar explicitamente um menu.  
  
 Percorra a lista tem as desvantagens que é um pouco mais lenta e requer o gerenciamento de intervalos de ID de recurso. Ele tem a vantagem de que um aplicativo cliente que contém links para várias DLLs de extensão do MFC pode usar qualquer recurso fornecido DLL sem ter que especificar o identificador de instância DLL. `AfxFindResourceHandle` uma API é usada para percorrer a lista de recursos para procurar uma correspondência determinada. Ele usa o nome e um tipo de recurso e retorna o identificador de recurso em que ele foi encontrado primeiro (ou nulo).  
  
##  <a name="_mfcnotes_writing_an_application_that_uses_the_dll_version"></a> Escrevendo um aplicativo que usa a versão DLL  
  
### <a name="application-requirements"></a>Requisitos do aplicativo  
 Um aplicativo que usa a versão compartilhada do MFC deve seguir algumas regras simples:  
  
-   Ele deve ter um `CWinApp` do objeto e seguir as regras padrão para uma bomba de mensagem.  
  
-   Ele deve ser compilado com um conjunto de sinalizadores de compilador necessário (veja abaixo).  
  
-   Ele deve vincular com as bibliotecas de importação MFCxx. Ao definir os sinalizadores de compilador necessário, os cabeçalhos MFC determinam em tempo de link que deve ser vinculado com o aplicativo de biblioteca.  
  
-   Para executar o arquivo executável, MFCxx.DLL deve ser o caminho ou no diretório de sistema do Windows.  
  
### <a name="building-with-the-development-environment"></a>Compilando com o ambiente de desenvolvimento  
 Se você estiver usando o makefile interno com a maioria dos padrões padrão, você pode alterar facilmente o projeto para criar a versão DLL.  
  
 As etapas a seguir supõe que você tiver um aplicativo MFC funcionar corretamente vinculado com NAFXCWD. LIB (para depuração) e NAFXCW. LIB (para o varejo) e quiser convertê-lo para usar a versão compartilhada da biblioteca do MFC. Você estiver executando o ambiente do Visual C++ e tem um arquivo de projeto internos.  
  
1.  Sobre o **projetos** menu, clique em **propriedades**. No **geral** página em **padrões do projeto**, definir a Microsoft Foundation Classes **Use MFC em uma DLL compartilhada** (MFCxx(d).dll).  
  
### <a name="building-with-nmake"></a>Compilando com NMAKE  
 Se você estiver usando o recurso externo makefile do Visual C++, ou estiver usando NMAKE diretamente, você precisará editar o makefile para dar suporte a opções do vinculador e compilador  
  
 Sinalizadores de compilador necessário:  
  
 **/ /MD D_AFXDLL**  
 **/ D_AFXDLL**  
  
 Os cabeçalhos do MFC padrão necessário Este símbolo a ser definido:  
  
 **/MD**  
 O aplicativo deve usar a versão DLL da biblioteca de tempo de execução do C  
  
 Todos os outros sinalizadores de compilador siga os padrões MFC (por exemplo, Debug para depuração).  
  
 Edite a lista de vinculador de bibliotecas. Alteração NAFXCWD. LIB para MFCxxD.LIB e altere NAFXCW. LIB para MFCxx.LIB. Substitua LIBC. LIB com MSVCRT. LIB. Como com qualquer outra biblioteca MFC é importante que MFCxxD.LIB é colocado **antes de** as bibliotecas de tempo de execução C.  
  
 Opcionalmente, adicione **/D_AFXDLL** seu comerciais e depuração opções do compilador de recurso (que, na verdade, compila os recursos com **/R**). Isso torna o executável final menor compartilhando os recursos que estão presentes nas DLLs MFC.  
  
 Uma recriação completa é necessária depois que essas alterações são feitas.  
  
### <a name="building-the-samples"></a>Compilando os exemplos  
 A maioria dos programas de exemplo do MFC pode ser criada de Visual C++ ou de um MAKEFILE NMAKE compatível compartilhado da linha de comando.  
  
 Para converter qualquer um desses exemplos para usar MFCxx.DLL, você pode carregar o. MAK o arquivo em Visual C++ e defina as opções de projeto, conforme descrito acima. Se você estiver usando a compilação NMAKE, você pode especificar "AFXDLL = 1" na NMAKE linha de comando e que criará o exemplo usando as bibliotecas MFC compartilhadas.  
  
 O exemplo de conceitos avançados do MFC [DLLHUSK](../visual-cpp-samples.md) é criado com a versão DLL do MFC. Não somente, este exemplo ilustra como criar um aplicativo vinculado com MFCxx.DLL, mas ele também ilustra a outros recursos da opção de empacotamento de DLL MFC como DLLs de extensão do MFC descrito posteriormente nesta nota técnica.  
  
### <a name="packaging-notes"></a>Notas de empacotamento  
 A versão comercial das DLLs (MFCxx [U]. DLL) são redistribuíveis livremente. A versão de depuração das DLLs não são redistribuível gratuitamente e deve ser usado somente durante o desenvolvimento de seu aplicativo.  
  
 A depuração de DLLs são fornecidos com as informações de depuração. Usando o depurador do Visual C++, você pode rastrear a execução de seu aplicativo, bem como a DLL. As DLLs de versão (MFCxx [U]. DLL) não contêm informações de depuração.  
  
 Se você personaliza ou recriar as DLLs, em seguida, você deve chamá-los algo diferente de arquivo "MFCxx" o MFC SRC MFCDLL. MAK descreve as opções de compilação e contém a lógica para renomear a DLL. Renomear os arquivos é necessário, pois essas DLLs potencialmente são compartilhados por muitos aplicativos MFC. Com sua versão personalizada do substituir MFC DLLs estiverem instalados no sistema podem quebrar o outro aplicativo de MFC com as MFC DLLs compartilhadas.  
  
 Não é recomendável recriar as DLLs do MFC.  
  
##  <a name="_mfcnotes_how_the_mfc30.dll_is_implemented"></a> Como o MFCxx.DLL é implementado  
 A seção a seguir descreve como a DLL do MFC (MFCxx.DLL e MFCxxD.DLL) é implementada. Noções básicas sobre que os detalhes aqui também não são importantes se você quiser fazer é usar a DLL do MFC com seu aplicativo. Os detalhes aqui não são essenciais para compreender como escrever uma DLL de extensão do MFC, mas entender essa implementação pode ajudá-lo a escrever seu próprios DLL.  
  
### <a name="implementation-overview"></a>Visão geral da implementação  
 A DLL do MFC é realmente um caso especial de uma DLL de extensão do MFC, conforme descrito acima. Ele tem um número muito grande de exportações para um grande número de classes. Há algumas coisas adicionais fazemos a DLL do MFC que torná-lo ainda mais especiais que uma DLL de extensão do MFC regular.  
  
### <a name="win32-does-most-of-the-work"></a>Win32 faz a maior parte do trabalho  
 A versão de 16 bits de MFC necessárias várias técnicas especiais, incluindo dados por aplicativo no segmento de pilha, segmentos especiais criados por um código de assembly de 80 x86, contextos de exceção por processo e outras técnicas. Win32 diretamente dá suporte a dados de cada processo em uma DLL, que é o que você deseja que a maioria do tempo. Na maior parte MFCxx.DLL é NAFXCW apenas. LIB contida em uma DLL. Se você examinar o código-fonte MFC, você encontrará _AFXDLL #ifdef muito poucos, pois há muito poucos casos especiais que precisam ser feitas. Os casos especiais que existem especificamente lidar com Win32 no Windows 3.1 (também conhecido como Win32s). Win32s não não suporte por processo DLL dados diretamente para a DLL do MFC deve usar o armazenamento local de thread (TLS) APIs do Win32 para obter dados de local de processo.  
  
### <a name="impact-on-library-sources-additional-files"></a>Impacto em fontes de biblioteca, arquivos adicionais  
 O impacto de **_AFXDLL** versão em cabeçalhos e as fontes de biblioteca de classe do MFC normal é relativamente pequenos. Há uma versão especial do arquivo (AFXV_DLL. H), bem como um arquivo de cabeçalho adicionais (AFXDLL_. H) incluído por AFXWIN o principal. Cabeçalho de H. AFXDLL_. Cabeçalho H inclui o **CDynLinkLibrary** classe e outros detalhes de implementação de ambos **_AFXDLL** aplicativos e DLLs de extensão do MFC. AFXDLLX. H cabeçalho é fornecido para a criação de DLLs de extensão do MFC (consulte acima para obter detalhes).  
  
 As origens regulares à biblioteca do MFC em MFC SRC têm algum código condicional adicional sob o **_AFXDLL** #ifdef. Um arquivo de origem adicionais (DLLINIT. CPP) contém o código de inicialização de DLL extra e outros união para a versão compartilhada do MFC.  
  
 Para criar a versão compartilhada do MFC, arquivos adicionais são fornecidos. (Consulte abaixo para obter detalhes sobre como criar a DLL).  
  
-   Dois. Arquivos DEF são usados para exportar os pontos de entrada de DLL do MFC para depuração (MFCxxD.DEF) e versão (MFCxx.DEF) versões da DLL.  
  
-   Um arquivo. Arquivo RC (MFCDLL. RC) contém todos os recursos padrão do MFC e um recurso VERSIONINFO para a DLL.  
  
-   A. Arquivo CLW (MFCDLL. CLW) é fornecido permitir a navegação do MFC de classes usando ClassWizard. Observação: esse recurso não é específico para a versão DLL do MFC.  
  
### <a name="memory-management"></a>Gerenciamento de memória  
 Um aplicativo usando MFCxx.DLL usa um alocador de memória comuns fornecido por MSVCRTxx.DLL, a DLL compartilhada do tempo de execução C. O aplicativo, quaisquer DLLs de extensão do MFC, bem como as MFC DLLs se usam esse alocador de memória compartilhada. Usando uma DLL compartilhada para alocação de memória, as DLLs MFC pode alocar memória é liberada posteriormente pelo aplicativo ou vice-versa. Porque o aplicativo e a DLL devem usar o mesmo alocador, você não deve substituir o C++ global `operator new` ou `operator delete`. As mesmas regras se aplicam ao restante das rotinas de alocação de memória de tempo de execução do C (como `malloc`, `realloc`, **livre**e outros).  
  
### <a name="ordinals-and-class-declspecdllexport-and-dll-naming"></a>Ordinais e classe dllexport e nomeação de DLL  
 Nós não usamos o `class` **dllexport** funcionalidade do compilador C++. Em vez disso, uma lista de exportações está incluída com as fontes de biblioteca de classe (MFCxx.DEF e MFCxxD.DEF). Apenas esses selecione conjunto de pontos de entrada (funções e dados) são exportados. Não são exportados outros símbolos, como funções de implementação privada do MFC ou classes, todas as exportações são feitas por ordinal sem um nome de cadeia de caracteres na tabela de nomes residentes ou não residentes.  
  
 Usando `class` **dllexport** pode ser uma alternativa viável para a criação de DLLs menores, mas no caso de uma DLL grande como MFC, o padrão de exportação de mecanismo tem a eficiência e a capacidade de limites.  
  
 Isso significa que todas as novidades que podemos pode empacotar uma grande quantidade de recursos da versão MFCxx.DLL só é aproximadamente 800 KB sem comprometer muito execução ou velocidade de carregamento. MFCxx.DLL seria de 100 mil maior essa técnica não tivesse sido usado. Isso também torna possível adicionar pontos de entrada adicionais no final da. Arquivo de definição para permitir que o controle de versão simple sem comprometer a eficiência de velocidade e tamanho de exportação por ordinal. Revisões de versão principal da biblioteca de classes MFC alterará o nome da biblioteca. Ou seja, MFC30. DLL é redistribuível DLL que contém a versão 3.0 da biblioteca de classes MFC. Uma atualização dessa dll, digamos, em um 3.1 MFC hipotético, a DLL será nomeada MFC31. DLL em vez disso. Novamente, se você modificar o código-fonte MFC para produzir uma versão personalizada da DLL do MFC, use um nome diferente (e preferencialmente sem "MFC" no nome).  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

