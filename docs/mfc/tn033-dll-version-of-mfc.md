---
title: 'TN033: versão DLL do MFC'
ms.date: 06/28/2018
helpviewer_keywords:
- MFC DLLs [MFC], writing MFC extension DLLS
- AFXDLL library
- DLLs [MFC], MFC
- DLL version of MFC [MFC]
- TN033
ms.assetid: b6f1080b-b66b-4b1e-8fb1-926c5816392c
ms.openlocfilehash: c627f891efc893f4eb8dae4bfb0b3b78f7af1a46
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215927"
---
# <a name="tn033-dll-version-of-mfc"></a>TN033: versão DLL do MFC

Esta observação descreve como você pode usar o MFCxx.DLL e MFCxxD.DLL (em que x é o número de versão do MFC) bibliotecas de vínculo dinâmico compartilhado com aplicativos MFC e DLLs de extensão MFC. Para obter mais informações sobre DLLs do MFC regulares, consulte [usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md).

Esta nota técnica abrange três aspectos de DLLs. Os dois últimos são para os usuários mais avançados:

- [Como criar uma DLL de extensão do MFC](#_mfcnotes_how_to_write_an_mfc_extension_dll)

- [Como criar um aplicativo MFC que usa a versão DLL do MFC](#_mfcnotes_writing_an_application_that_uses_the_dll_version)

- [Como as bibliotecas de vínculo dinâmico compartilhado do MFC são implementadas](#_mfcnotes_how_the_mfc30.dll_is_implemented)

Se você estiver interessado em criar uma DLL usando o MFC que possa ser usado com aplicativos não MFC (isso é chamado de DLL do MFC regular), consulte a [Observação técnica 11](../mfc/tn011-using-mfc-as-part-of-a-dll.md).

## <a name="overview-of-mfcxxdll-support-terminology-and-files"></a>Visão geral do suporte a MFCxx.DLL: terminologia e arquivos

**Dll do MFC regular**: você usa uma DLL do MFC regular para criar uma DLL autônoma usando algumas das classes do MFC. As interfaces no limite do aplicativo/DLL são interfaces "C" e o aplicativo cliente não precisa ser um aplicativo do MFC.

Esta é a versão do suporte de DLL com suporte no MFC 1,0. Ele é descrito na [Observação técnica 11](../mfc/tn011-using-mfc-as-part-of-a-dll.md) e no exemplo de conceitos avançados do MFC [DLLScreenCap](../overview/visual-cpp-samples.md).

> [!NOTE]
> A partir da versão Visual C++ 4,0, o termo **USRDLL** é obsoleto e foi substituído por uma DLL do MFC regular que vincula ESTATICAMENTE ao MFC. Você também pode criar uma DLL do MFC regular que vincula dinamicamente ao MFC.

O MFC 3,0 (e superior) dá suporte a DLLs regulares do MFC com toda a nova funcionalidade, incluindo as classes OLE e Database.

**AFXDLL**: isso também é conhecido como a versão compartilhada das bibliotecas do MFC. Esse é o novo suporte a DLL adicionado no MFC 2,0. A própria biblioteca do MFC está em várias DLLs (descritas abaixo) e um aplicativo cliente ou DLL vincula dinamicamente as DLLs necessárias. As interfaces entre os limites Application/DLL são interfaces de classe C++/MFC. O aplicativo cliente deve ser um aplicativo MFC. Isso dá suporte a todas as funcionalidades do MFC 3,0 (exceção: o UNICODE não tem suporte para as classes de banco de dados).

> [!NOTE]
> A partir da versão Visual C++ 4,0, esse tipo de DLL é chamado de "DLL de extensão".

Esta observação usará MFCxx.DLL para fazer referência a todo o conjunto de DLL do MFC, que inclui:

- Debug: MFCxxD.DLL (combinado) e MFCSxxD. LIB (estático).

- Versão: MFCxx.DLL (combinado) e MFCSxx. LIB (estático).

- Depuração Unicode: MFCxxUD.DLL (combinado) e MFCSxxD. LIB (estático).

- Versão Unicode: MFCxxU.DLL (combinado) e MFCSxxU. LIB (estático).

> [!NOTE]
> O MFCSxx [U] [D]. Bibliotecas LIB são usadas em conjunto com as DLLs compartilhadas do MFC. Essas bibliotecas contêm código que deve ser vinculado estaticamente ao aplicativo ou DLL.

Um aplicativo é vinculado às bibliotecas de importação correspondentes:

- Depurar: MFCxxD. LIB

- Versão: MFCxx. LIB

- Depuração Unicode: MFCxxUD. LIB

- Versão Unicode: MFCxxU. LIB

Uma "DLL de extensão do MFC" é uma DLL criada sobre MFCxx.DLL (e/ou outras DLLs compartilhadas do MFC). Aqui, a arquitetura do componente do MFC é acionada. Se você derivar uma classe útil de uma classe do MFC ou criar outro kit de ferramentas semelhante ao MFC, poderá colocá-la em uma DLL. Essa DLL usa MFCxx.DLL, assim como o aplicativo cliente definitivo. Isso permite classes de folha reutilizáveis, classes base reutilizáveis e classes de exibição/documento reutilizáveis.

## <a name="pros-and-cons"></a>Prós e contras

Por que você deve usar a versão compartilhada do MFC

- O uso da biblioteca compartilhada pode resultar em aplicativos menores (um aplicativo mínimo que usa a maior parte da biblioteca do MFC é inferior a 10K).

- A versão compartilhada do MFC dá suporte a DLLs de extensão MFC e DLLs regulares do MFC.

- Criar um aplicativo que usa as bibliotecas MFC compartilhadas é mais rápido do que criar um aplicativo MFC vinculado estaticamente porque não é necessário vincular o próprio MFC. Isso é especialmente verdadeiro em compilações de **depuração** em que o vinculador deve compactar as informações de depuração — vinculando com uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar em seu aplicativo.

Por que você não deve usar a versão compartilhada do MFC:

- O envio de um aplicativo que usa a biblioteca compartilhada requer que você envie a biblioteca MFCxx.DLL (e outros) com seu programa. MFCxx.DLL é redistribuível livremente como muitas DLLs, mas você ainda deve instalar a DLL em seu programa de instalação. Além disso, você deve enviar o MSVCRTxx.DLL, que contém a biblioteca de tempo de execução C, que é usada pelo seu programa e pelas próprias DLLs do MFC.

## <a name="how-to-write-an-mfc-extension-dll"></a><a name="_mfcnotes_how_to_write_an_mfc_extension_dll"></a>Como escrever uma DLL de extensão do MFC

Uma DLL de extensão do MFC é uma DLL que contém classes e funções escritas para aprimorar a funcionalidade das classes do MFC. Uma DLL de extensão do MFC usa as DLLs do MFC compartilhado da mesma maneira que um aplicativo a usa, com algumas considerações adicionais:

- O processo de compilação é semelhante à criação de um aplicativo que usa as bibliotecas do MFC compartilhado com algumas opções adicionais de compilador e vinculador.

- Uma DLL de extensão do MFC não tem uma `CWinApp` classe derivada.

- Uma DLL de extensão do MFC deve fornecer um especial `DllMain` . AppWizard fornece uma `DllMain` função que você pode modificar.

- Uma DLL de extensão do MFC geralmente fornecerá uma rotina de inicialização para criar um `CDynLinkLibrary` se a DLL de extensão do MFC quiser exportar `CRuntimeClass` os es ou recursos para o aplicativo. Uma classe derivada de `CDynLinkLibrary` poderá ser usada se os dados por aplicativo precisarem ser mantidos pela DLL de extensão do MFC.

Essas considerações são descritas em mais detalhes abaixo. Você também deve consultar os conceitos avançados do MFC de exemplo [DLLHUSK](../overview/visual-cpp-samples.md) , já que ele ilustra:

- Criando um aplicativo usando as bibliotecas compartilhadas. (DLLHUSK.EXE é um aplicativo MFC que se vincula dinamicamente às bibliotecas MFC, bem como a outras DLLs.)

- Criando uma DLL de extensão do MFC. (Observe os sinalizadores especiais, como os `_AFXEXT` que são usados na criação de uma DLL de extensão do MFC)

- Dois exemplos de DLLs de extensão do MFC. Uma mostra a estrutura básica de uma DLL de extensão do MFC com exportações limitadas (TESTDLL1) e a outra mostra a exportação de uma interface de classe inteira (TESTDLL2).

O aplicativo cliente e qualquer DLL de extensão MFC devem usar a mesma versão do MFCxx.DLL. Você deve seguir a Convenção da DLL do MFC e fornecer uma versão de depuração e de varejo (/Release) da sua DLL de extensão do MFC. Isso permite que os programas cliente criem versões de depuração e de varejo de seus aplicativos e vincule-os com a versão apropriada de depuração ou de varejo de todas as DLLs.

> [!NOTE]
> Como os problemas de desgerenciamento e exportação de nome C++, a lista de exportação de uma DLL de extensão do MFC pode ser diferente entre as versões de depuração e de varejo da mesma DLL e DLLs para diferentes plataformas. O MFCxx.DLL de varejo tem cerca de 2000 pontos de entrada exportados; o MFCxxD.DLL de depuração tem cerca de 3000 pontos de entrada exportados.

### <a name="quick-note-on-memory-management"></a>Observação rápida sobre o gerenciamento de memória

A seção intitulada "gerenciamento de memória", próximo ao final desta nota técnica, descreve a implementação do MFCxx.DLL com a versão compartilhada do MFC. As informações que você precisa saber para implementar apenas uma DLL de extensão do MFC são descritas aqui.

MFCxx.DLL e todas as DLLs de extensão do MFC carregadas no espaço de endereço de um aplicativo cliente usarão o mesmo alocador de memória, carregamento de recursos e outros Estados "globais" do MFC como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas de DLL não MFC e as DLLs do MFC regulares que se vinculam estaticamente ao MFC fazem o oposto exato e têm cada DLL alocando-se de seu próprio pool de memória.

Se uma DLL de extensão do MFC alocar memória, essa memória poderá misturar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que usa as bibliotecas MFC compartilhadas falhar, a proteção do sistema operacional manterá a integridade de qualquer outro aplicativo MFC que compartilha a DLL.

Da mesma forma, outros Estados de MFC "globais", como o arquivo executável atual para carregar recursos, também são compartilhados entre o aplicativo cliente e todas as DLLs de extensão do MFC, bem como MFCxx.DLL em si.

### <a name="building-an-mfc-extension-dll"></a>Criando uma DLL de extensão do MFC

Você pode usar AppWizard para criar um projeto de DLL de extensão do MFC e ele gerará automaticamente as configurações apropriadas do compilador e do vinculador. Ele também foi gerado uma `DllMain` função que você pode modificar.

Se você estiver convertendo um projeto existente para uma DLL de extensão do MFC, comece com as regras padrão para criar um aplicativo usando a versão compartilhada do MFC e, em seguida, faça o seguinte:

- Adicione **/D_AFXEXT** aos sinalizadores do compilador. Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria de pré-processador. Adicione `_AFXEXT` ao campo definir macros, separando cada um dos itens com ponto-e-vírgula.

- Remova a opção de compilador **/GY** . Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria geração de código. Verifique se a opção "Habilitar vinculação no nível de função" não está habilitada. Isso facilitará a exportação de classes, pois o vinculador não removerá funções não referenciadas. Se o projeto original for usado para criar uma DLL do MFC regular vinculada estaticamente ao MFC, altere a opção de compilador **/mt [d]** para **/MD [d]**.

- Crie uma biblioteca de exportação com a opção **/dll** para vincular. Isso será definido quando você criar um novo destino, especificando a biblioteca de vínculo dinâmico do Win32 como o tipo de destino.

### <a name="changing-your-header-files"></a>Alterando os arquivos de cabeçalho

A meta de uma DLL de extensão do MFC geralmente é exportar algumas funcionalidades comuns para um ou mais aplicativos que podem usar essa funcionalidade. Isso se resume à exportação de classes e funções globais que estão disponíveis para seus aplicativos cliente.

Para fazer isso, você deve garantir que cada uma das funções de membro seja marcada como importação ou exportação, conforme apropriado. Isso requer declarações especiais: `__declspec(dllexport)` e `__declspec(dllimport)` . Quando suas classes são usadas pelos aplicativos cliente, você deseja que elas sejam declaradas como `__declspec(dllimport)` . Quando a própria DLL de extensão do MFC está sendo criada, elas devem ser declaradas como `__declspec(dllexport)` . Além disso, as funções devem ser realmente exportadas, para que os programas cliente se associem a elas no tempo de carregamento.

Para exportar toda a sua classe, use `AFX_EXT_CLASS` na definição de classe. Essa macro é definida pela estrutura como `__declspec(dllexport)` quando `_AFXDLL` e `_AFXEXT` é definida, mas definida como `__declspec(dllimport)` quando `_AFXEXT` não está definida. `_AFXEXT`conforme descrito acima, é definido apenas ao criar sua DLL de extensão do MFC. Por exemplo:

```cpp
class AFX_EXT_CLASS CExampleExport : public CObject
{ /* ... class definition ... */ };
```

### <a name="not-exporting-the-entire-class"></a>Não exportando toda a classe

Às vezes, talvez você queira exportar apenas os membros individuais necessários da sua classe. Por exemplo, se você estiver exportando uma `CDialog` classe derivada de uma, talvez seja necessário apenas exportar o construtor e a `DoModal` chamada. Você pode exportar esses membros usando as DLLs. Arquivo DEF, mas você também pode usar `AFX_EXT_CLASS` praticamente da mesma forma nos membros individuais que você precisa exportar.

Por exemplo:

```cpp
class CExampleDialog : public CDialog
{
public:
    AFX_EXT_CLASS CExampleDialog();
    AFX_EXT_CLASS int DoModal();
    // rest of class definition
    // ...
};
```

Ao fazer isso, você pode encontrar um problema adicional porque não está mais exportando todos os membros da classe. O problema está no modo como as macros do MFC funcionam. Várias macros auxiliares do MFC, na verdade, declaram ou definem membros de dados. Portanto, esses membros de dados também precisarão ser exportados da sua DLL.

Por exemplo, a macro DECLARE_DYNAMIC é definida da seguinte maneira ao criar uma DLL de extensão do MFC:

```cpp
#define DECLARE_DYNAMIC(class_name) \
protected: \
    static CRuntimeClass* PASCAL _GetBaseClass(); \
    public: \
    static AFX_DATA CRuntimeClass class##class_name; \
    virtual CRuntimeClass* GetRuntimeClass() const; \
```

A linha que começa "Static `AFX_DATA` " está declarando um objeto estático dentro de sua classe. Para exportar essa classe corretamente e acessar as informações de tempo de execução de um cliente. EXE, você precisa exportar esse objeto estático. Como o objeto estático é declarado com o modificador `AFX_DATA` , você só precisa definir `AFX_DATA` para ser `__declspec(dllexport)` ao compilar sua dll e defini-la como `__declspec(dllimport)` ao criar o executável do cliente.

Conforme discutido acima, `AFX_EXT_CLASS` já está definido dessa maneira. Você só precisa redefinir `AFX_DATA` para ser o mesmo que a definição de `AFX_EXT_CLASS` sua classe.

Por exemplo:

```cpp
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

O MFC sempre usa o `AFX_DATA` símbolo em itens de dados que ele define em suas macros, portanto, essa técnica funcionará para todos esses cenários. Por exemplo, ele funcionará para DECLARE_MESSAGE_MAP.

> [!NOTE]
> Se você estiver exportando toda a classe em vez de membros selecionados da classe, os membros de dados estáticos serão exportados automaticamente.

Você pode usar a mesma técnica para exportar automaticamente o `CArchive` operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Exporte o operador Archive colocando as declarações de classe entre colchetes (localizadas no. Arquivo H) com o seguinte código:

```cpp
#undef AFX_API
#define AFX_API AFX_EXT_CLASS

/* your class declarations here */

#undef AFX_API
#define AFX_API
```

### <a name="limitations-of-_afxext"></a>Limitações de _AFXEXT

Você pode usar o símbolo de pré-processador _**AFXEXT** para suas DLLs de extensão do MFC, desde que você não tenha várias camadas de DLLs de extensão do MFC. Se você tiver DLLs de extensão do MFC que chamam ou derivam de classes em suas próprias DLLs de extensão do MFC, que derivam das classes do MFC, você deve usar seu próprio símbolo de pré-processador para evitar ambigüidade.

O problema é que, no Win32, você deve declarar explicitamente quaisquer dados como `__declspec(dllexport)` se ele fosse exportado de uma dll, e `__declspec(dllimport)` se for para ser importado de uma dll. Quando você define `_AFXEXT` , os cabeçalhos do MFC verificam se `AFX_EXT_CLASS` estão definidos corretamente.

Quando você tem várias camadas, um símbolo como `AFX_EXT_CLASS` não é suficiente, uma vez que uma DLL de extensão do MFC pode estar exportando novas classes, bem como importando outras classes de outra DLL de extensão do MFC. Para lidar com esse problema, use um símbolo de pré-processador especial que indica que você está criando a DLL em si versus usando a DLL. Por exemplo, imagine duas DLLs de extensão do MFC, A.DLL e B.DLL. Cada uma delas exporta algumas classes em A. H e B. H, respectivamente. B.DLL usa as classes de A.DLL. Os arquivos de cabeçalho teriam uma aparência semelhante a esta:

```cpp
/* A.H */
#ifdef A_IMPL
    #define CLASS_DECL_A   __declspec(dllexport)
#else
    #define CLASS_DECL_A   __declspec(dllimport)
#endif

class CLASS_DECL_A CExampleA : public CObject
{ /* ... class definition ... */ };

/* B.H */
#ifdef B_IMPL
    #define CLASS_DECL_B   __declspec(dllexport)
#else
    #define CLASS_DECL_B   __declspec(dllimport)
#endif

class CLASS_DECL_B CExampleB : public CExampleA
{ /* ... class definition ... */ };
```

Quando A.DLL é compilado, ele é compilado com **/DA_IMPL** e quando B.DLL é compilado, ele é criado com **/DB_IMPL**. Usando símbolos separados para cada DLL, CExampleB é exportado e CExampleA é importado ao criar B.DLL. CExampleA é exportado ao criar A.DLL e importado quando usado por B.DLL (ou algum outro cliente).

Esse tipo de disposição em camadas não pode ser feito ao usar os `AFX_EXT_CLASS` símbolos internos e de `_AFXEXT` pré-processador. A técnica descrita acima resolve esse problema de uma maneira que não é diferente do próprio mecanismo que o MFC usa ao criar suas DLLs de extensão OLE, de banco de dados e de rede.

### <a name="not-exporting-the-entire-class"></a>Não exportando toda a classe

Novamente, você precisará tomar cuidado especial quando não estiver exportando uma classe inteira. Você precisa garantir que os itens de dados necessários criados pelas macros do MFC sejam exportados corretamente. Isso pode ser feito redefinindo `AFX_DATA` a macro de sua classe específica. Isso deve ser feito sempre que você não estiver exportando a classe inteira.

Por exemplo:

```cpp
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
    // class definition
    // ...
};

#undef AFX_DATA
#define AFX_DATA
```

### <a name="dllmain"></a>DllMain

Este é o código exato que você deve inserir em seu arquivo de origem principal para sua DLL de extensão do MFC. Ele deve vir após a inclusão padrão. Observe que quando você usa o AppWizard para criar arquivos iniciais para uma DLL de extensão do MFC, ele fornece um `DllMain` para você.

```cpp
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

A chamada para `AfxInitExtensionModule` captura os módulos Runtime-classes ( `CRuntimeClass` estruturas), bem como suas fábricas de objeto ( `COleObjectFactory` objetos) para uso posterior quando o `CDynLinkLibrary` objeto é criado. A chamada (opcional) para `AfxTermExtensionModule` permite que o MFC Limpe a DLL de extensão do MFC quando cada processo é desanexado (o que acontece quando o processo é encerrado, ou quando a dll é descarregada como resultado de uma `FreeLibrary` chamada) da DLL de extensão do MFC. Como a maioria das DLLs de extensão MFC não são carregadas dinamicamente (geralmente, elas são vinculadas por meio de suas bibliotecas de importação), normalmente, a chamada para `AfxTermExtensionModule` não é necessária.

Se seu aplicativo carregar e liberar DLLs de extensão do MFC dinamicamente, certifique-se de chamar `AfxTermExtensionModule` conforme mostrado acima. Além disso, certifique-se de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez de funções do Win32 `LoadLibrary` e `FreeLibrary` ) se seu aplicativo usar vários threads ou se ele carregar dinamicamente uma DLL de extensão do MFC. Usar `AfxLoadLibrary` e `AfxFreeLibrary` garantir que o código de inicialização e desligamento seja executado quando a DLL de extensão do MFC for carregada e descarregada não corromper o estado global do MFC.

O arquivo de cabeçalho AFXDLLX. H contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a definição de `AFX_EXTENSION_MODULE` e `CDynLinkLibrary` .

O *extensionDLL* global deve ser declarado como mostrado. Ao contrário da versão de 16 bits do MFC, você pode alocar memória e chamar funções MFC durante esse tempo, uma vez que o MFCxx.DLL é totalmente inicializado quando o `DllMain` é chamado.

### <a name="sharing-resources-and-classes"></a>Compartilhando recursos e classes

DLLs de extensão do MFC simples precisam exportar apenas algumas funções de baixa largura de banda para o aplicativo cliente e nada mais. Mais DLLs com uso intensivo de interface do usuário podem querer exportar recursos e classes do C++ para o aplicativo cliente.

A exportação de recursos é feita por meio de uma lista de recursos. Em cada aplicativo, há uma lista de objetos vinculada individualmente `CDynLinkLibrary` . Ao procurar um recurso, a maioria das implementações padrão do MFC que carregam os recursos parecem primeiro no módulo do recurso atual ( `AfxGetResourceHandle` ) e, se não for encontrada, percorra a lista de `CDynLinkLibrary` objetos tentando carregar o recurso solicitado.

A criação dinâmica de objetos C++ considerando um nome de classe C++ é semelhante. O mecanismo de desserialização do objeto MFC precisa ter todos os `CRuntimeClass` objetos registrados para que possa reconstruir criando dinamicamente o objeto C++ do tipo necessário com base no que foi armazenado anteriormente.

Se você quiser que o aplicativo cliente use classes em sua DLL de extensão do MFC `DECLARE_SERIAL` , você precisará exportar suas classes para que fiquem visíveis para o aplicativo cliente. Isso também é feito ao percorrer a `CDynLinkLibrary` lista.

No caso dos conceitos avançados do MFC, exemplo [DLLHUSK](../overview/visual-cpp-samples.md), a lista é semelhante a:

```Example
head ->   DLLHUSK.EXE   - or - DLLHUSK.EXE
               |                    |
          TESTDLL2.DLL         TESTDLL2.DLL
               |                    |
          TESTDLL1.DLL         TESTDLL1.DLL
               |                    |
               |                    |
           MFC90D.DLL           MFC90.DLL
```

O MFCxx.DLL geralmente é o último na lista de recursos e classes. MFCxx.DLL inclui todos os recursos padrão do MFC, incluindo cadeias de caracteres de prompt para todas as IDs de comando padrão. Colocá-lo na parte final da lista permite que as DLLs e o próprio aplicativo cliente não tenham uma cópia própria dos recursos padrão do MFC, mas para contar com os recursos compartilhados na MFCxx.DLL em vez disso.

Mesclar os recursos e os nomes de classe de todas as DLLs no espaço de nome do aplicativo cliente tem a desvantagem de ter cuidado com quais IDs ou nomes você escolhe. É claro que você pode desabilitar esse recurso não exportando seus recursos ou um `CDynLinkLibrary` objeto para o aplicativo cliente. O exemplo [DLLHUSK](../overview/visual-cpp-samples.md) gerencia o espaço de nome de recurso compartilhado usando vários arquivos de cabeçalho. Consulte a [Observação técnica 35](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md) para obter mais dicas sobre como usar arquivos de recursos compartilhados.

### <a name="initializing-the-dll"></a>Inicializando a DLL

Como mencionado acima, geralmente você desejará criar um `CDynLinkLibrary` objeto para exportar seus recursos e classes para o aplicativo cliente. Você precisará fornecer um ponto de entrada exportado para inicializar a DLL. Minimamente, essa é uma rotina void que não usa nenhum argumento e não retorna nada, mas pode ser qualquer coisa que você desejar.

Cada aplicativo cliente que deseja usar sua DLL deve chamar essa rotina de inicialização, se você usar essa abordagem. Você também pode alocar esse `CDynLinkLibrary` objeto no seu `DllMain` logo após a chamada `AfxInitExtensionModule` .

A rotina de inicialização deve criar um `CDynLinkLibrary` objeto no heap do aplicativo atual, com conexão com suas informações de DLL de extensão do MFC. Isso pode ser feito com o seguinte:

```cpp
extern "C" extern void WINAPI InitXxxDLL()
{
    new CDynLinkLibrary(extensionDLL);
}
```

O nome da rotina, *InitXxxDLL* neste exemplo, pode ser qualquer coisa que você desejar. Ele não precisa ser **externo "C"**, mas isso torna a lista de exportação mais fácil de manter.

> [!NOTE]
> Se você usar a DLL de extensão do MFC de uma DLL do MFC regular, deverá exportar essa função de inicialização. Essa função deve ser chamada da DLL do MFC regular antes de usar qualquer recurso ou classes DLL de extensão do MFC.

### <a name="exporting-entries"></a>Exportando entradas

A maneira simples de exportar suas classes é usar `__declspec(dllimport)` e `__declspec(dllexport)` em cada classe e função global que você deseja exportar. Isso o torna muito mais fácil, mas é menos eficiente do que nomear cada ponto de entrada (descrito abaixo), já que você tem menos controle sobre quais funções são exportadas e não pode exportar as funções por ordinal. TESTDLL1 e TESTDLL2 usam esse método para exportar suas entradas.

Um método mais eficiente (e o método usado pelo MFCxx.DLL) é exportar cada entrada manualmente, nomeando cada entrada no. Arquivo DEF. Como estamos exportando exportações seletivas de nossa DLL (ou seja, não tudo), devemos decidir quais interfaces específicas desejamos exportar. Isso é difícil, pois você deve especificar os nomes desconfigurados para o vinculador na forma de entradas no. Arquivo DEF. Não exporte nenhuma classe C++, a menos que você realmente precise ter um link simbólico para ela.

Se você tentou exportar classes C++ com um. Arquivo DEF antes, talvez você queira desenvolver uma ferramenta para gerar essa lista automaticamente. Isso pode ser feito usando um processo de link de duas etapas. Vincule sua DLL uma vez sem exportações e permita que o vinculador gere um. Arquivo de mapa. Dos. O arquivo de mapa pode ser usado para gerar uma lista de funções que devem ser exportadas, portanto, com algumas reorganizaçãos, ela pode ser usada para gerar suas entradas de exportação para seu. Arquivo DEF. A lista de exportação para MFCxx.DLL e as DLLs de extensão do MFC OLE e do banco de dados, vários milhares de números, foram geradas com esse processo (embora não seja completamente automática e exija algum ajuste a cada uma vez em alguns instantes).

### <a name="cwinapp-vs-cdynlinklibrary"></a>CWinApp vs. CDynLinkLibrary

Uma DLL de extensão do MFC não tem um `CWinApp` objeto derivado de si mesma; em vez disso, ela deve trabalhar com o `CWinApp` objeto derivado do aplicativo cliente. Isso significa que o aplicativo cliente possui a bomba principal de mensagem, o loop ocioso e assim por diante.

Se a DLL de extensão do MFC precisar manter dados adicionais para cada aplicativo, você poderá derivar uma nova classe de `CDynLinkLibrary` e criá-la na rotina InitXxxDLL descrita acima. Durante a execução, a DLL pode verificar a lista de objetos do aplicativo atual `CDynLinkLibrary` para encontrar aquele para essa DLL de extensão de MFC específica.

### <a name="using-resources-in-your-dll-implementation"></a>Usando recursos em sua implementação de DLL

Conforme mencionado acima, a carga de recursos padrão percorrerá a lista de `CDynLinkLibrary` objetos procurando o primeiro exe ou DLL que tem o recurso solicitado. Todas as APIs do MFC, bem como todo o código interno `AfxFindResourceHandle` , usam o para orientar a lista de recursos para localizar qualquer recurso, independentemente de onde ele possa residir.

Se você quiser carregar apenas os recursos de um local específico, use as APIs `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o identificador antigo e definir o novo identificador. Certifique-se de restaurar o identificador de recurso antigo antes de retornar para o aplicativo cliente. O TESTDLL2 de exemplo usa essa abordagem para carregar explicitamente um menu.

A movimentação da lista tem as desvantagens de que é um pouco mais lenta e requer o gerenciamento de intervalos de ID de recurso. Ele tem a vantagem de que um aplicativo cliente que se vincula a várias DLLs de extensão MFC pode usar qualquer recurso fornecido por DLL sem precisar especificar o identificador da instância de DLL. `AfxFindResourceHandle`é uma API usada para percorrer a lista de recursos para procurar uma determinada correspondência. Ele usa o nome e o tipo de um recurso e retorna o identificador de recurso onde ele foi encontrado pela primeira vez (ou nulo).

## <a name="writing-an-application-that-uses-the-dll-version"></a><a name="_mfcnotes_writing_an_application_that_uses_the_dll_version"></a>Gravando um aplicativo que usa a versão de DLL

### <a name="application-requirements"></a>Requisitos do aplicativo

Um aplicativo que usa a versão compartilhada do MFC deve seguir algumas regras simples:

- Ele deve ter um `CWinApp` objeto e seguir as regras padrão para uma bomba de mensagem.

- Ele deve ser compilado com um conjunto de sinalizadores de compilador necessários (veja abaixo).

- Ele deve vincular com as bibliotecas de importação do MFCxx. Ao definir os sinalizadores de compilador necessários, os cabeçalhos do MFC determinam no momento do link a qual biblioteca o aplicativo deve vincular.

- Para executar o executável, MFCxx.DLL deve estar no caminho ou no diretório do sistema do Windows.

### <a name="building-with-the-development-environment"></a>Criando com o ambiente de desenvolvimento

Se você estiver usando o makefile interno com a maioria dos padrões padrão, poderá alterar facilmente o projeto para criar a versão de DLL.

A etapa a seguir pressupõe que você tenha um aplicativo MFC funcionando corretamente vinculado ao NAFXCWD. LIB (para depuração) e NAFXCW. LIB (para varejo) e você deseja convertê-lo para usar a versão compartilhada da biblioteca do MFC. Você está executando o ambiente de Visual C++ e tem um arquivo de projeto interno.

1. No menu **projetos** , clique em **Propriedades**. Na página **geral** , em **padrões do projeto**, defina MFC para **usar MFC em uma DLL compartilhada** (MFCxx (d). dll).

### <a name="building-with-nmake"></a>Criando com NMAKE

Se você estiver usando o recurso de makefile externo do Visual C++, ou estiver usando NMAKE diretamente, precisará editar seu makefile para dar suporte a opções de compilador e vinculador

Sinalizadores de compilador necessários:

- **/D_AFXDLL/MD** 
   **/D_AFXDLL**

Os cabeçalhos padrão do MFC precisam que este símbolo seja definido:

- **/MD** O aplicativo deve usar a versão de DLL da biblioteca de tempo de execução do C

Todos os outros sinalizadores de compilador seguem os padrões do MFC (por exemplo, _DEBUG para depuração).

Edite a lista de bibliotecas do vinculador. Altere NAFXCWD. LIB para MFCxxD. LIB e alterar NAFXCW. LIB para MFCxx. LIB. Substitua LIBC. LIB com MSVCRT. LIB. Assim como acontece com qualquer outra biblioteca do MFC, é importante que MFCxxD. LIB seja colocado **antes** de qualquer biblioteca de tempo de execução em C.

Opcionalmente, adicione **/D_AFXDLL** às opções do compilador de recurso de depuração e de varejo (aquela que realmente compila os recursos com **/r**). Isso torna o executável final menor, compartilhando os recursos que estão presentes nas DLLs do MFC.

Uma recompilação completa é necessária depois que essas alterações são feitas.

### <a name="building-the-samples"></a>Criando exemplos

A maioria dos programas de exemplo MFC pode ser criada a partir de Visual C++ ou de um MAKEFILE compartilhado compatível com NMAKE da linha de comando.

Para converter qualquer um desses exemplos para usar MFCxx.DLL, você pode carregar o. O arquivo MAK na Visual C++ e define as opções de projeto, conforme descrito acima. Se você estiver usando a compilação NMAKE, será possível especificar "AFXDLL = 1" na linha de comando NMAKE e isso criará o exemplo usando as bibliotecas MFC compartilhadas.

O exemplo de conceitos avançados do MFC [DLLHUSK](../overview/visual-cpp-samples.md) é criado com a versão da dll do MFC. Este exemplo não apenas ilustra como criar um aplicativo vinculado com MFCxx.DLL, mas também ilustra outros recursos da opção de empacotamento de DLL do MFC, como DLLs de extensão do MFC descritas posteriormente nesta nota técnica.

### <a name="packaging-notes"></a>Notas de empacotamento

A versão comercial das DLLs (MFCxx [U]. DLL) são redistribuíveis livremente. A versão de depuração das DLLs não é redistribuível livremente e deve ser usada somente durante o desenvolvimento do seu aplicativo.

As DLLs de depuração são fornecidas com informações de depuração. Usando o depurador de Visual C++, você pode rastrear a execução do seu aplicativo, bem como a DLL. As DLLs de versão (MFCxx [U]. DLL) não contém informações de depuração.

Se você personalizar ou recriar as DLLs, deverá chamá-las de algo diferente de "MFCxx" o arquivo SRC do MFC MFCDLL. A MAK descreve as opções de compilação e contém a lógica para renomear a DLL. É necessário renomear os arquivos, pois essas DLLs são potencialmente compartilhadas por vários aplicativos MFC. Ter sua versão personalizada das DLLs do MFC substitui-las instaladas no sistema pode interromper outro aplicativo MFC usando as DLLs do MFC compartilhado.

Não é recomendável recompilar as DLLs do MFC.

## <a name="how-the-mfcxxdll-is-implemented"></a><a name="_mfcnotes_how_the_mfc30.dll_is_implemented"></a>Como o MFCxx.DLL é implementado

A seção a seguir descreve como a DLL do MFC (MFCxx.DLL e MFCxxD.DLL) é implementada. Entender os detalhes aqui também não é importante se tudo o que você deseja fazer é usar a DLL do MFC com seu aplicativo. Os detalhes aqui não são essenciais para entender como escrever uma DLL de extensão do MFC, mas entender essa implementação pode ajudá-lo a escrever sua própria DLL.

### <a name="implementation-overview"></a>Visão geral da implementação

A DLL do MFC é, na verdade, um caso especial de uma DLL de extensão do MFC, conforme descrito acima. Ele tem um número muito grande de exportações para um grande número de classes. Há algumas coisas adicionais que fazemos na DLL do MFC que o tornam ainda mais especial do que uma DLL de extensão do MFC regular.

### <a name="win32-does-most-of-the-work"></a>O Win32 faz a maior parte do trabalho

A versão de 16 bits do MFC precisava de várias técnicas especiais, incluindo dados por aplicativo no segmento de pilha, segmentos especiais criados por alguns códigos de assembly 80x86, contextos de exceção por processo e outras técnicas. O Win32 dá suporte direto a dados por processo em uma DLL, que é o que você deseja na maioria das vezes. Para a maior parte MFCxx.DLL é apenas NAFXCW. LIB empacotado em uma DLL. Se você examinar o código-fonte do MFC, encontrará muito poucos #ifdef _AFXDLL, já que há poucos casos especiais que precisam ser feitos. Os casos especiais que existem especificamente para lidar com o Win32 no Windows 3,1 (também conhecido como Win32s). Os Win32s não dão suporte a dados de DLL por processo diretamente, de modo que a DLL do MFC deve usar as APIs do protocolo TLS (armazenamento local de thread) para obter dados locais do processo.

### <a name="impact-on-library-sources-additional-files"></a>Impacto em fontes de biblioteca, arquivos adicionais

O impacto da versão **_AFXDLL** nas fontes e cabeçalhos normais da biblioteca de classes do MFC é relativamente menor. Há um arquivo de versão especial (AFXV_DLL. H), bem como um arquivo de cabeçalho adicional (AFXDLL_. H) incluído pelo AFXWIN principal. Cabeçalho H. O AFXDLL_. O cabeçalho H inclui a `CDynLinkLibrary` classe e outros detalhes de implementação de `_AFXDLL` aplicativos e DLLs de extensão MFC. O AFXDLLX. O cabeçalho H é fornecido para a criação de DLLs de extensão MFC (veja acima para obter detalhes).

As fontes regulares da biblioteca do MFC na SRC têm algum código condicional adicional na `_AFXDLL` #ifdef. Um arquivo de origem adicional (DLLINIT. CPP) contém o código de inicialização de DLL extra e outras cola para a versão compartilhada do MFC.

Para criar a versão compartilhada do MFC, são fornecidos arquivos adicionais. (Consulte abaixo para obter detalhes sobre como criar a DLL.)

- Duas. Os arquivos DEF são usados para exportar os pontos de entrada da DLL do MFC para versões de depuração (MFCxxD. DEF) e Release (MFCxx. DEF) da DLL.

- Um. Arquivo RC (MFCDLL. RC) contém todos os recursos padrão do MFC e um recurso VERSIONINFO para a DLL.

- Um. Arquivo CLW (MFCDLL. CLW) é fornecido para permitir a navegação pelas classes do MFC usando o ClassWizard. Observação: esse recurso não é específico para a versão de DLL do MFC.

### <a name="memory-management"></a>Gerenciamento de memória

Um aplicativo usando o MFCxx.DLL usa um alocador de memória comum fornecido pelo MSVCRTxx.DLL, a DLL de tempo de execução compartilhada em C. O aplicativo, todas as DLLs de extensão do MFC e também as DLLs do MFC usam esse alocador de memória compartilhada. Usando uma DLL compartilhada para alocação de memória, as DLLs do MFC podem alocar memória que é liberada posteriormente pelo aplicativo ou vice-versa. Como o aplicativo e a DLL devem usar o mesmo alocador, você não deve substituir o operador global C++ **New** ou o **operador Delete**. As mesmas regras se aplicam ao restante das rotinas de alocação de memória de tempo de execução C (como **malloc**, **realloc**, **Free**e Other).

### <a name="ordinals-and-class-__declspecdllexport-and-dll-naming"></a>Ordinais e __declspec de classe (dllexport) e nomenclatura de DLL

Não usamos a `class` **`__declspec(dllexport)`** funcionalidade do compilador C++. Em vez disso, uma lista de exportações é incluída com as fontes da biblioteca de classes (MFCxx. DEF e MFCxxD. DEF). Somente esses conjuntos de pontos de entrada (funções e dados) selecionados são exportados. Outros símbolos, como funções de implementação privada do MFC ou classes, não são exportadas todas as exportações são feitas por ordinal sem um nome de cadeia de caracteres na tabela de nomes residente ou não residente.

O uso do `class` **`__declspec(dllexport)`** pode ser uma alternativa viável para criar DLLs menores, mas no caso de uma DLL grande, como o MFC, o mecanismo de exportação padrão tem limites de capacidade e eficiência.

Isso tudo significa que podemos empacotar uma grande quantidade de funcionalidades na versão MFCxx.DLL que só cerca de 800 KB, sem comprometer muita execução ou velocidade de carregamento. MFCxx.DLL teria sido 100 mil de que essa técnica não foi usada. Isso também torna possível adicionar pontos de entrada adicionais no final do. Arquivo DEF para permitir o controle de versão simples sem comprometer a velocidade e a eficiência de tamanho da exportação por ordinal. As revisões de versão principais na biblioteca de classes do MFC alterarão o nome da biblioteca. Ou seja, MFC30.DLL é a DLL redistribuível que contém a versão 3,0 da biblioteca de classes do MFC. Uma atualização dessa DLL, digamos, em um MFC 3,1 hipotético, a DLL seria nomeada MFC31.DLL em vez disso. Novamente, se você modificar o código-fonte do MFC para produzir uma versão personalizada da DLL do MFC, use um nome diferente (e, preferencialmente, um sem "MFC" no nome).

## <a name="see-also"></a>Confira também

[Notas técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Notas técnicas por categoria](../mfc/technical-notes-by-category.md)
