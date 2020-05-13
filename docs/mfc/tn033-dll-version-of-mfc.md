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
ms.openlocfilehash: ad4cb883cfe7e397cf599d659afb02b23501dc5a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370320"
---
# <a name="tn033-dll-version-of-mfc"></a>TN033: versão DLL do MFC

Esta nota descreve como você pode usar as bibliotecas de link dinâmicas MFCxx.DLL e MFCxxD.DLL (onde x é o número da versão MFC) bibliotecas de links dinâmicos compartilhadas com aplicativos MFC e DLLs de extensão MFC. Para obter mais informações sobre DLLs MFC regulares, consulte [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md).

Esta nota técnica abrange três aspectos das DLLs. Os dois últimos são para usuários mais avançados:

- [Como você constrói uma DLL de extensão MFC](#_mfcnotes_how_to_write_an_mfc_extension_dll)

- [Como você constrói um aplicativo MFC que usa a versão DLL do MFC](#_mfcnotes_writing_an_application_that_uses_the_dll_version)

- [Como as bibliotecas de links dinâmicos compartilhados do MFC são implementadas](#_mfcnotes_how_the_mfc30.dll_is_implemented)

Se você estiver interessado em construir uma DLL usando MFC que pode ser usada com aplicações não-MFC (isso é chamado de DLL MFC regular), consulte a [Nota Técnica 11](../mfc/tn011-using-mfc-as-part-of-a-dll.md).

## <a name="overview-of-mfcxxdll-support-terminology-and-files"></a>Visão geral do suporte MFCxx.DLL: Terminologia e Arquivos

**DLL MFC regular**: Você usa uma DLL MFC regular para construir uma DLL autônoma usando algumas das classes de MFC. Interfaces através do limite App/DLL são interfaces "C" e o aplicativo cliente não precisa ser um aplicativo MFC.

Esta é a versão do suporte ao DLL suportado no MFC 1.0. Ele é descrito na [Nota Técnica 11](../mfc/tn011-using-mfc-as-part-of-a-dll.md) e na amostra MFC Advanced Concepts [DLLScreenCap](../overview/visual-cpp-samples.md).

> [!NOTE]
> A partir da versão 4.0 do Visual C++, o termo **USRDLL** é obsoleto e foi substituído por um DLL MFC regular que se liga estáticamente ao MFC. Você também pode construir um DLL MFC regular que se vincula dinamicamente ao MFC.

O MFC 3.0 (e acima) suporta DLLs MFC regulares com todas as novas funcionalidades, incluindo as classes OLE e Database.

**AFXDLL**: Isso também é referido como a versão compartilhada das bibliotecas MFC. Este é o novo suporte dll adicionado no MFC 2.0. A biblioteca MFC em si está em uma série de DLLs (descritos abaixo) e um aplicativo cliente ou DLL vincula dinamicamente as DLLs que ela requer. Interfaces através do limite de aplicativo/DLL são interfaces de classe C++/MFC. A aplicação do cliente DEVE ser um aplicativo MFC. Isso suporta todas as funcionalidades do MFC 3.0 (exceção: UNICODE não é suportado para as classes de banco de dados).

> [!NOTE]
> A partir da versão 4.0 do Visual C++, este tipo de DLL é referido como um "DLL de extensão".

Esta nota usará MFCxx.DLL para se referir a todo o conjunto MFC DLL, que inclui:

- Depuração: MFCxxD.DLL (combinado) e MFCSxxD.LIB (estático).

- Versão: MFCxx.DLL (combinado) e MFCSxx.LIB (estático).

- Depuração Unicode: MFCxxUD.DLL (combinado) e MFCSxxD.LIB (estático).

- Versão Unicode: MFCxxU.DLL (combinado) e MFCSxxU.LIB (estático).

> [!NOTE]
> O MFCSxx[U][D]. Bibliotecas LIB são usadas em conjunto com os DLLs compartilhados do MFC. Essas bibliotecas contêm códigos que devem estar estáticamente ligados ao aplicativo ou DLL.

Um aplicativo é vinculado às bibliotecas de importação correspondentes:

- Depuração: MFCxxD.LIB

- Lançamento: MFCxx.LIB

- Depuração Unicode: MFCxxUD.LIB

- Versão Unicode: MFCxxU.LIB

Um "MFC Extension DLL" é um DLL construído sobre MFCxx.DLL (e/ou os outros DLLs compartilhados do MFC). Aqui, a arquitetura de componentes Do MFC entra em ação. Se você derivar uma classe útil de uma classe MFC ou construir outro kit de ferramentas semelhante ao MFC, você pode colocá-lo em um DLL. Essa DLL usa MFCxx.DLL, assim como o aplicativo cliente final. Isso permite classes de folha reutilizáveis, classes de base reutilizáveis e classes de exibição/documento reutilizáveis.

## <a name="pros-and-cons"></a>Prós e Contras

Por que você deve usar a versão compartilhada do MFC

- O uso da biblioteca compartilhada pode resultar em aplicativos menores (um aplicativo mínimo que usa a maioria da biblioteca MFC é inferior a 10K).

- A versão compartilhada do MFC suporta DLLs de extensão MFC e DLLs MFC regulares.

- Construir um aplicativo que use as bibliotecas MFC compartilhadas é mais rápido do que construir um aplicativo MFC estáticamente vinculado porque não é necessário vincular o próprio MFC. Isso é especialmente verdadeiro nas compilações **DEBUG** onde o linker deve compactar as informações de depuração — ao vincular-se a uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar dentro de sua aplicação.

Por que você não deve usar a versão compartilhada do MFC:

- O envio de um aplicativo que usa a biblioteca compartilhada requer que você enviar a biblioteca MFCxx.DLL (e outros) com o seu programa. MFCxx.DLL é livremente redibitável como muitos DLLs, mas você ainda deve instalar o DLL em seu programa de configuração. Além disso, você deve enviar o MSVCRTxx.DLL, que contém a biblioteca C-runtime que é usada tanto pelo seu programa quanto pelos próprios DLLs do MFC.

## <a name="how-to-write-an-mfc-extension-dll"></a><a name="_mfcnotes_how_to_write_an_mfc_extension_dll"></a>Como escrever uma DLL de extensão mfc

Um DLL de extensão MFC é uma DLL contendo classes e funções escritas para embelezar a funcionalidade das classes MFC. Um DLL de extensão MFC usa os DLLs MFC compartilhados da mesma forma que um aplicativo o usa, com algumas considerações adicionais:

- O processo de compilação é semelhante à construção de um aplicativo que usa as bibliotecas MFC compartilhadas com algumas opções adicionais de compilador e linker.

- Um DLL de extensão `CWinApp`MFC não tem uma classe derivada.

- Uma DLL de extensão `DllMain`MFC deve fornecer uma dLL especial . O AppWizard `DllMain` fornece uma função que você pode modificar.

- Uma DLL de extensão do MFC geralmente `CDynLinkLibrary` fornecerá uma rotina de `CRuntimeClass`inicialização para criar um se a DLL de extensão do MFC desejar exportar es ou recursos para o aplicativo. Uma classe derivada pode `CDynLinkLibrary` ser usada se os dados por aplicativo devem ser mantidos pela dLL de extensão MFC.

Essas considerações são descritas com mais detalhes abaixo. Você também deve consultar a amostra De conceitos avançados do MFC [DLLHUSK,](../overview/visual-cpp-samples.md) uma vez que ilustra:

- Construindo um aplicativo usando as bibliotecas compartilhadas. (DLLHUSK. EXE é um aplicativo MFC que se vincula dinamicamente às bibliotecas MFC, bem como a outros DLLs.)

- Construindo um DLL de extensão MFC. (Observe as bandeiras `_AFXEXT` especiais como as que são usadas na construção de uma dll de extensão MFC)

- Dois exemplos de DLLs de extensão MFC. Um mostra a estrutura básica de uma DLL de extensão MFC com exportações limitadas (TESTDLL1) e a outra mostra a exportação de uma interface de classe inteira (TESTDLL2).

Tanto o aplicativo cliente quanto qualquer DLL de extensão MFC devem usar a mesma versão do MFCxx.DLL. Você deve seguir a convenção do MFC DLL e fornecer uma versão de depuração e varejo (/lançamento) da sua dLL de extensão MFC. Isso permite que os programas de clientes construam versões de depuração e varejo de seus aplicativos e os vinculem à versão apropriada de depuração ou varejo de todos os DLLs.

> [!NOTE]
> Como c++ nome ou problemas de exportação, a lista de exportação de uma extensão MFC DLL pode ser diferente entre as versões de depuração e varejo das mesmas DLL e DLLs para diferentes plataformas. O varejo MFCxx.DLL tem cerca de 2000 pontos de entrada exportados; o debug MFCxxD.DLL tem cerca de 3000 pontos de entrada exportados.

### <a name="quick-note-on-memory-management"></a>Nota rápida sobre gerenciamento de memória

A seção intitulada "Gerenciamento de Memória", perto do final desta nota técnica, descreve a implementação do MFCxx.DLL com a versão compartilhada do MFC. As informações que você precisa saber para implementar apenas uma dLL de extensão MFC são descritas aqui.

MFCxx.DLL e todos os DLLs de extensão MFC carregados no espaço de endereço de um aplicativo cliente usarão o mesmo alocador de memória, carregamento de recursos e outros estados "globais" do MFC como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas dll não-MFC e DLLs MFC regulares que se conectam esticamente ao MFC fazem exatamente o oposto e têm cada DLL alocando fora de seu próprio pool de memória.

Se uma extensão MFC DLL alocar memória, então essa memória pode se misturar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que usa as bibliotecas MFC compartilhadas falhar, a proteção do sistema operacional manterá a integridade de qualquer outro aplicativo MFC compartilhando o DLL.

Da mesma forma, outros estados mfc "globais", como o arquivo executável atual para carregar recursos, também são compartilhados entre o aplicativo cliente e todos os DLLs de extensão MFC, bem como o próprio MFCxx.DLL.

### <a name="building-an-mfc-extension-dll"></a>Construindo uma extensão MFC DLL

Você pode usar o AppWizard para criar um projeto DLL de extensão MFC, e ele gerará automaticamente as configurações apropriadas de compilador e linker. Também foi gerar `DllMain` uma função que você pode modificar.

Se você estiver convertendo um projeto existente em um DLL de extensão MFC, comece com as regras padrão para construir um aplicativo usando a versão compartilhada do MFC e faça o seguinte:

- Adicione **/D_AFXEXT** às bandeiras do compilador. Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria Pré-processador. Adicione `_AFXEXT` ao campo Definir macros, separando cada um dos itens com ponto e vírgula.

- Remova o interruptor do compilador **/Gy.** Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria Geração de código. Certifique-se de que a opção "Ativar vinculação em nível de função" não está ativada. Isso facilitará a exportação de classes porque o linker não removerá funções não referenciadas. Se o projeto original for usado para construir uma DLL MFC regular estáticamente ligada ao MFC, altere a opção de compilador **/MT[d]** para **/MD[d]**.

- Construa uma biblioteca de exportação com a opção **/DLL** para LINK. Isso será definido quando você criar um novo alvo, especificando a Biblioteca de Elo Dinâmico do Win32 como o tipo de destino.

### <a name="changing-your-header-files"></a>Alterando seus arquivos de cabeçalho

O objetivo de uma dLL de extensão MFC geralmente é exportar alguma funcionalidade comum para um ou mais aplicativos que possam usar essa funcionalidade. Isso se resume a classes de exportação e funções globais disponíveis para seus aplicativos clientes.

Para isso, você deve garantir que cada uma das funções do membro esteja marcada como importação ou exportação conforme apropriado. Isso requer declarações `__declspec(dllexport)` `__declspec(dllimport)`especiais: e . Quando suas classes são usadas pelos aplicativos cliente, você `__declspec(dllimport)`quer que elas sejam declaradas como . Quando a própria extensão MFC DLL estiver sendo `__declspec(dllexport)`construída, elas devem ser declaradas como . Além disso, as funções devem ser realmente exportadas, de modo que os programas do cliente se vinculem a eles no tempo de carga.

Para exportar toda `AFX_EXT_CLASS` a sua classe, use na definição da classe. Esta macro é definida `__declspec(dllexport)` pelo `_AFXDLL` `_AFXEXT` quadro como quando `__declspec(dllimport)` e `_AFXEXT` é definida, mas definida como quando não é definida. `_AFXEXT`como descrito acima, só é definido ao construir sua extensão MFC DLL. Por exemplo:

```cpp
class AFX_EXT_CLASS CExampleExport : public CObject
{ /* ... class definition ... */ };
```

### <a name="not-exporting-the-entire-class"></a>Não exportando toda a classe

Às vezes você pode querer exportar apenas os membros individuais necessários de sua classe. Por exemplo, se você `CDialog`estiver exportando uma classe derivada, você `DoModal` só pode precisar exportar o construtor e a chamada. Você pode exportar esses membros usando os DLL's . Arquivo DEF, mas você `AFX_EXT_CLASS` também pode usar da mesma forma nos membros individuais que você precisa exportar.

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

Quando você faz isso, você pode encontrar um problema adicional porque você não está mais exportando todos os membros da classe. O problema está na forma como as macros MFC funcionam. Várias das macros auxiliares do MFC realmente declaram ou definem membros de dados. Portanto, esses membros de dados também precisarão ser exportados de sua DLL.

Por exemplo, a DECLARE_DYNAMIC macro é definida da seguinte forma ao construir uma DLL de extensão MFC:

```cpp
#define DECLARE_DYNAMIC(class_name) \
protected: \
    static CRuntimeClass* PASCAL _GetBaseClass(); \
    public: \
    static AFX_DATA CRuntimeClass class##class_name; \
    virtual CRuntimeClass* GetRuntimeClass() const; \
```

A linha que `AFX_DATA`começa "estática" está declarando um objeto estático dentro da sua classe. Para exportar esta classe corretamente e acessar as informações de tempo de execução de um cliente . EXE, você precisa exportar este objeto estático. Como o objeto estático é `AFX_DATA`declarado com o `AFX_DATA` modificador, você só precisa definir como ser `__declspec(dllexport)` ao construir sua DLL e defini-lo como `__declspec(dllimport)` ao construir o executável do seu cliente.

Como discutido acima, `AFX_EXT_CLASS` já está definido dessa forma. Você só precisa redefinir `AFX_DATA` para ser `AFX_EXT_CLASS` o mesmo que em torno de sua definição de classe.

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

O MFC `AFX_DATA` sempre usa o símbolo em itens de dados que define dentro de suas macros, de modo que essa técnica funcionará para todos esses cenários. Por exemplo, funcionará para DECLARE_MESSAGE_MAP.

> [!NOTE]
> Se você estiver exportando toda a classe em vez de membros selecionados da classe, os membros de dados estáticos serão automaticamente exportados.

Você pode usar a mesma técnica `CArchive` para exportar automaticamente o operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Exporte o operador de arquivo por meio de suporte às declarações de classe (localizadas no . Arquivo H) com o seguinte código:

```cpp
#undef AFX_API
#define AFX_API AFX_EXT_CLASS

/* your class declarations here */

#undef AFX_API
#define AFX_API
```

### <a name="limitations-of-_afxext"></a>Limitações de _AFXEXT

Você pode usar o símbolo de pré-processador _**AFXEXT** para seus DLLs de extensão MFC, desde que você não tenha várias camadas de DLLs de extensão MFC. Se você tiver DLLs de extensão MFC que chamam ou derivam de classes em seus próprios DLLs de extensão MFC, que derivam das classes MFC, você deve usar seu próprio símbolo de pré-processador para evitar a ambiguidade.

O problema é que, no Win32, você `__declspec(dllexport)` deve declarar explicitamente qualquer dado como `__declspec(dllimport)` se fosse para ser exportado de uma DLL, e se ele for importado de uma DLL. Quando você `_AFXEXT`definir, os cabeçalhos MFC certifiquem-se de que `AFX_EXT_CLASS` está definido corretamente.

Quando você tem várias camadas, um símbolo como `AFX_EXT_CLASS` não é suficiente, uma vez que uma DLL de extensão MFC pode estar exportando novas classes, bem como importando outras classes de outra DLL de extensão MFC. Para lidar com esse problema, use um símbolo especial de pré-processador que indique que você está construindo a própria DLL em vez de usar o DLL. Por exemplo, imagine dois DLLs de extensão MFC, A.DLL e B.DLL. Cada um exporta algumas classes em A.H e B.H, respectivamente. B.DLL usa as classes da A.DLL. Os arquivos de cabeçalho seriam mais ou menos assim:

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

Quando a A.DLL é construída, ela é construída com **/DA_IMPL** e quando a B.DLL é construída, ela é construída com **/DB_IMPL**. Usando símbolos separados para cada DLL, CExampleB é exportado e CExampleA é importado ao construir B.DLL. CExampleA é exportado ao construir A.DLL e importado quando usado por B.DLL (ou algum outro cliente).

Esse tipo de camada não pode ser `AFX_EXT_CLASS` feito `_AFXEXT` ao usar os símbolos embutidos e pré-processadores. A técnica descrita acima resolve esse problema de uma maneira não muito diferente do mecanismo que o próprio MFC usa ao construir seus DLLs de extensão OLE, Database e Network MFC.

### <a name="not-exporting-the-entire-class"></a>Não exportando toda a classe

Novamente, você terá que tomar cuidado especial quando não estiver exportando uma classe inteira. Você tem que garantir que os itens de dados necessários criados pelas macros MFC sejam exportados corretamente. Isso pode ser feito `AFX_DATA` redefinindo para a macro da sua classe específica. Isso deve ser feito sempre que você não estiver exportando toda a classe.

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

### <a name="dllmain"></a>Dllmain

A seguir está o código exato que você deve colocar em seu arquivo principal de origem para a sua extensão MFC DLL. Deve vir depois que o padrão inclui. Observe que quando você usa o AppWizard para criar arquivos iniciais `DllMain` para uma dLL de extensão MFC, ele fornece um para você.

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

A chamada `AfxInitExtensionModule` para capturar os módulos`CRuntimeClass` de classes de tempo de`COleObjectFactory` execução (estruturas) `CDynLinkLibrary` bem como suas fábricas de objetos (objetos) para uso posteriormente quando o objeto é criado. A chamada (opcional) `AfxTermExtensionModule` permite que o MFC limpe a dLL de extensão MFC quando cada processo se destaca (o `FreeLibrary` que acontece quando o processo sai, ou quando o DLL é descarregado como resultado de uma chamada) da dLL de extensão MFC. Como a maioria dos DLLs de extensão MFC não são carregados dinamicamente (geralmente, eles são vinculados através de suas bibliotecas de importação), a chamada para `AfxTermExtensionModule` geralmente não é necessária.

Se o aplicativo carregar e liberar DLLs de extensão `AfxTermExtensionModule` MFC dinamicamente, certifique-se de ligar como mostrado acima. Certifique-se também `AfxLoadLibrary` `AfxFreeLibrary` de usar e (em `LoadLibrary` `FreeLibrary`vez de funções Win32 e ) se o aplicativo usar vários threads ou se ele carrega dinamicamente uma DLL de extensão MFC. O `AfxLoadLibrary` `AfxFreeLibrary` uso e assedia que o código de inicialização e desligamento que é executado quando a DLL de extensão MFC é carregada e descarregada não corrompe o estado MFC global.

O arquivo de cabeçalho AFXDLLX. H contém definições especiais para estruturas usadas em DLLs `AFX_EXTENSION_MODULE` de `CDynLinkLibrary`extensão MFC, como a definição para e .

A *extensão globalDLL* deve ser declarada conforme mostrado. Ao contrário da versão de 16 bits do MFC, você pode alocar memória e chamar funções de MFC durante este tempo, uma vez que o MFCxx.DLL é totalmente inicializado no momento em que você `DllMain` é chamado.

### <a name="sharing-resources-and-classes"></a>Compartilhando Recursos e Classes

Os DLLs de extensão MFC simples precisam exportar apenas algumas funções de baixa largura de banda para o aplicativo cliente e nada mais. DLLs mais intensivos de interface do usuário podem querer exportar recursos e classes C++ para o aplicativo cliente.

A exportação de recursos é feita através de uma lista de recursos. Em cada aplicação há uma lista `CDynLinkLibrary` de objetos cada vez mais ligados. Ao procurar um recurso, a maioria das implementações padrão de MFC`AfxGetResourceHandle`que carregam recursos olham primeiro `CDynLinkLibrary` para o módulo de recurso atual ( ) e, se não forem encontrados, andam a lista de objetos que tentam carregar o recurso solicitado.

A criação dinâmica de objetos C++ dado um nome de classe C++ é semelhante. O mecanismo de desserialização de objetos MFC precisa ter todos os `CRuntimeClass` objetos registrados para que ele possa reconstruir criando dinamicamente o objeto C++ do tipo necessário com base no que foi armazenado anteriormente.

Se você quiser que o aplicativo cliente use classes `DECLARE_SERIAL`em sua dLL de extensão MFC que são, então você precisará exportar suas classes para ser visível para o aplicativo cliente. Isso também é feito `CDynLinkLibrary` andando na lista.

No caso da amostra MFC Advanced Concepts [DLLHUSK](../overview/visual-cpp-samples.md), a lista se parece com:

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

O MFCxx.DLL geralmente é o último na lista de recursos e classes. MFCxx.DLL inclui todos os recursos padrão do MFC, incluindo strings prompt para todos os IDs de comando padrão. Colocá-lo na parte final da lista permite que os DLLs e o próprio aplicativo cliente não tenham uma cópia própria dos recursos padrão do MFC, mas que dependam dos recursos compartilhados no MFCxx.DLL.

A fusão dos recursos e nomes de classe de todos os DLLs no espaço de nome do aplicativo cliente tem a desvantagem de que você tem que ter cuidado com quais IDs ou nomes você escolhe. É claro que você pode desativar esse recurso não `CDynLinkLibrary` exportando seus recursos ou um objeto para o aplicativo cliente. A amostra [DLLHUSK](../overview/visual-cpp-samples.md) gerencia o espaço de nome de recurso compartilhado usando vários arquivos de cabeçalho. Consulte [nota técnica 35](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md) para obter mais dicas sobre como usar arquivos de recursos compartilhados.

### <a name="initializing-the-dll"></a>Inicializando o DLL

Como mencionado acima, você geralmente `CDynLinkLibrary` deseja criar um objeto para exportar seus recursos e classes para o aplicativo cliente. Você precisará fornecer um ponto de entrada exportado para inicializar o DLL. Minimamente, esta é uma rotina vazia que não aceita argumentos e não retorna nada, mas pode ser o que você quiser.

Cada aplicativo cliente que deseja usar sua DLL deve chamar essa rotina de inicialização, se você usar essa abordagem. Você também pode `CDynLinkLibrary` alocar `DllMain` este `AfxInitExtensionModule`objeto em seu justo após a chamada .

A rotina de inicialização deve criar um `CDynLinkLibrary` objeto no heap do aplicativo atual, conectado às informações de DLL de extensão do MFC. Isso pode ser feito com o seguinte:

```cpp
extern "C" extern void WINAPI InitXxxDLL()
{
    new CDynLinkLibrary(extensionDLL);
}
```

O nome de rotina, *InitXxxDLL* neste exemplo, pode ser o que você quiser. Ele não precisa ser **extern "C",** mas fazê-lo torna a lista de exportação mais fácil de manter.

> [!NOTE]
> Se você usar a dLL de extensão MFC de uma DLL MFC regular, você deve exportar esta função de inicialização. Esta função deve ser chamada do DLL MFC regular antes de usar quaisquer classes ou recursos dLL de extensão MFC.

### <a name="exporting-entries"></a>Entradas de Exportação

A maneira simples de exportar `__declspec(dllimport)` suas `__declspec(dllexport)` classes é usar e em cada classe e função global que você deseja exportar. Isso torna muito mais fácil, mas é menos eficiente do que nomear cada ponto de entrada (descrito abaixo) já que você tem menos controle sobre quais funções são exportadas e você não pode exportar as funções por ordinal. TESTDLL1 e TESTDLL2 usam este método para exportar suas entradas.

Um método mais eficiente (e o método usado por MFCxx.DLL) é exportar cada entrada manualmente, nomeando cada entrada no . Arquivo DEF. Uma vez que estamos exportando exportações seletivas da nossa DLL (ou seja, não tudo), devemos decidir quais interfaces específicas desejamos exportar. Isso é difícil, pois você deve especificar os nomes mutilados para o linker na forma de entradas no . Arquivo DEF. Não exporte nenhuma classe C++, a menos que você realmente precise ter um link simbólico para ele.

Se você tentou exportar classes C++ com a . Arquivo DEF antes, você pode querer desenvolver uma ferramenta para gerar essa lista automaticamente. Isso pode ser feito usando um processo de link de duas etapas. Vincule sua DLL uma vez sem exportações e permita que o linker gere um . Arquivo MAP. O. O arquivo MAP pode ser usado para gerar uma lista de funções que devem ser exportadas, de modo que, com algum rearranjo, ele pode ser usado para gerar suas entradas DE EXPORT PARA o seu . Arquivo DEF. A lista de exportação para MFCxx.DLL e os DLLs de extensão MFC do OLE e do Banco de Dados, vários milhares em número, foi gerada com esse processo (embora não seja completamente automático e exija alguma sintonia manual de vez em quando).

### <a name="cwinapp-vs-cdynlinklibrary"></a>CWinApp vs. CDynLinkLibrary

Um DLL de extensão `CWinApp`MFC não tem um objeto derivado próprio; em vez disso, `CWinApp`ele deve trabalhar com o objeto derivado do aplicativo cliente. Isso significa que o aplicativo cliente possui a bomba de mensagem principal, o loop ocioso e assim por diante.

Se o dLL de extensão do MFC precisa manter dados `CDynLinkLibrary` extras para cada aplicativo, você pode obter uma nova classe e criá-la na rotina InitXxxDLL descrita acima. Ao ser executado, o DLL pode verificar `CDynLinkLibrary` a lista de objetos do aplicativo atual para encontrar o dLL de extensão MFC em particular.

### <a name="using-resources-in-your-dll-implementation"></a>Usando recursos na implementação do DLL

Como mencionado acima, a carga de `CDynLinkLibrary` recursos padrão apresentará a lista de objetos que procuram o primeiro EXE ou DLL que tenha o recurso solicitado. Todas as APIs do MFC, `AfxFindResourceHandle` bem como todos os códigos internos, são utilizadas para andar na lista de recursos para encontrar qualquer recurso, não importa onde ele possa residir.

Se desejar carregar apenas recursos de um lugar `AfxGetResourceHandle` específico, use as APIs e `AfxSetResourceHandle` salve a alça antiga e defina a nova alça. Certifique-se de restaurar a alça de recurso antiga antes de retornar ao aplicativo do cliente. A amostra TESTDLL2 usa essa abordagem para carregar explicitamente um menu.

Andar na lista tem as desvantagens de que ela é um pouco mais lenta e requer o gerenciamento de faixas de ID de recursos. Ele tem a vantagem de que um aplicativo cliente que se vincula a vários DLLs de extensão MFC pode usar qualquer recurso fornecido pela DLL sem ter que especificar o cabo de instância DLL. `AfxFindResourceHandle`é uma API usada para andar na lista de recursos para procurar uma determinada correspondência. Ele pega o nome e o tipo de recurso e retorna a alça de recurso onde foi encontrado pela primeira vez (ou NULL).

## <a name="writing-an-application-that-uses-the-dll-version"></a><a name="_mfcnotes_writing_an_application_that_uses_the_dll_version"></a>Escrevendo um aplicativo que usa a versão DLL

### <a name="application-requirements"></a>Requisitos de aplicação

Um aplicativo que usa a versão compartilhada do MFC deve seguir algumas regras simples:

- Ele deve `CWinApp` ter um objeto e seguir as regras padrão para uma bomba de mensagem.

- Deve ser compilado com um conjunto de bandeiras compiladoras necessárias (veja abaixo).

- Ele deve se conectar com as bibliotecas de importação MFCxx. Ao definir os sinalizadores de compilador necessários, os cabeçalhos do MFC determinam no momento do link com qual biblioteca o aplicativo deve vincular.

- Para executar o executável, MFCxx.DLL deve estar no caminho ou no diretório do sistema Windows.

### <a name="building-with-the-development-environment"></a>Construção com o Ambiente de Desenvolvimento

Se você estiver usando o makefile interno com a maioria dos padrões padrão, você pode facilmente alterar o projeto para construir a versão DLL.

A etapa a seguir pressupõe que você tenha um aplicativo MFC em funcionamento correto vinculado ao NAFXCWD. LIB (para depuração) e NAFXCW. LIB (para varejo) e você deseja convertê-lo para usar a versão compartilhada da biblioteca MFC. Você está executando o ambiente Visual C++ e tem um arquivo de projeto interno.

1. No menu **Projetos,** clique em **Propriedades**. Na página **Geral** em **Project Defaults,** defina as classes da Microsoft Foundation para **usar o MFC em um DLL compartilhado** (MFCxx(d.dll).

### <a name="building-with-nmake"></a>Construção com NMAKE

Se você estiver usando o recurso de makefile externo do Visual C++, ou estiver usando o NMAKE diretamente, você terá que editar seu makefile para suportar opções de compilador e linker

Bandeiras de compilador necessárias:

- **/D_AFXDLL /MD**
   **/D_AFXDLL**

Os cabeçalhos Padrão MFC precisam que este símbolo seja definido:

- **/MD** O aplicativo deve usar a versão DLL da biblioteca de tempo de execução C

Todas as outras bandeiras de compilador seguem os padrões do MFC (por exemplo, _DEBUG para depuração).

Edite a lista de linker de bibliotecas. Mude NAFXCWD. LIB para MFCxxD.LIB e alterar NAFXCW. LIB para MFCxx.LIB. Substitua libc. LIB com MSVCRT. Lib. Como em qualquer outra biblioteca MFC, é importante que o MFCxxD.LIB seja colocado **antes** de qualquer biblioteca em tempo de execução C.

Opcionalmente, adicione **/D_AFXDLL** às opções de compilador de recursos de varejo e depuração (aquela que realmente compila os recursos com **/R**). Isso torna seu executável final menor, compartilhando os recursos presentes nos DLLs do MFC.

Uma reconstrução completa é necessária após essas alterações serem feitas.

### <a name="building-the-samples"></a>Criando exemplos

A maioria dos programas de amostra mfc pode ser construída a partir do Visual C++ ou de um MAKEFILE compatível com NMAKE compartilhado da linha de comando.

Para converter qualquer uma dessas amostras para usar MFCxx.DLL, você pode carregar o . Arquivo MAK no Visual C++ e defina as opções do Projeto conforme descrito acima. Se você estiver usando a compilação NMAKE, você pode especificar "AFXDLL=1" na linha de comando NMAKE e isso irá construir a amostra usando as bibliotecas MFC compartilhadas.

A amostra MFC Advanced Concepts [DLLHUSK](../overview/visual-cpp-samples.md) é construída com a versão DLL do MFC. Esta amostra não apenas ilustra como construir um aplicativo vinculado ao MFCxx.DLL, mas também ilustra outras características da opção de embalagem MFC DLL, como DLLs de extensão MFC descritas mais tarde nesta nota técnica.

### <a name="packaging-notes"></a>Notas de embalagem

A versão de varejo dos DLLs (MFCxx[U]. DLL) são livremente reditribuíveis. A versão de depuração dos DLLs não são livremente redisiputais e devem ser usadas apenas durante o desenvolvimento de sua aplicação.

Os DLLs de depuração são fornecidos com informações de depuração. Usando o depurador Visual C++, você pode rastrear a execução do seu aplicativo, bem como o DLL. Os DLLs de lançamento (MFCxx[U]. DLL) não contêm informações de depuração.

Se você personalizar ou reconstruir os DLLs, então você deve chamá-los de algo diferente de "MFCxx" O arquivo MFC SRC MFCDLL. Mak descreve opções de compilação e contém a lógica para renomear o DLL. Renomear os arquivos é necessário, uma vez que esses DLLs são potencialmente compartilhados por muitos aplicativos MFC. Ter sua versão personalizada dos DLLs MFC substituir aqueles instalados no sistema pode quebrar outro aplicativo MFC usando os DLLs MFC compartilhados.

A reconstrução dos DLLs Do MFC não é recomendada.

## <a name="how-the-mfcxxdll-is-implemented"></a><a name="_mfcnotes_how_the_mfc30.dll_is_implemented"></a>Como o MFCxx.DLL é implementado

A seção a seguir descreve como o MFC DLL (MFCxx.DLL e MFCxxD.DLL) é implementado. Entender os detalhes aqui também não é importante se tudo o que você quer fazer é usar o DLL MFC com sua aplicação. Os detalhes aqui não são essenciais para entender como escrever uma DLL de extensão MFC, mas entender essa implementação pode ajudá-lo a escrever sua própria DLL.

### <a name="implementation-overview"></a>Visão geral da implementação

O MFC DLL é realmente um caso especial de um DLL de extensão MFC como descrito acima. Tem um número muito grande de exportações para um grande número de classes. Existem algumas coisas adicionais que fazemos no MFC DLL que o tornam ainda mais especial do que uma dll de extensão MFC regular.

### <a name="win32-does-most-of-the-work"></a>Win32 Faz a Maior Parte do Trabalho

A versão de 16 bits do MFC precisava de uma série de técnicas especiais, incluindo dados por aplicativo no segmento stack, segmentos especiais criados por cerca de 80x86 código de montagem, contextos de exceção por processo e outras técnicas. O Win32 suporta diretamente dados por processo em uma DLL, que é o que você quer na maioria das vezes. Na maioria das vezes, MFCxx.DLL é apenas NAFXCW. LIB embalado em um DLL. Se você olhar para o código fonte do MFC, você encontrará muito poucos #ifdef _AFXDLL, uma vez que há muito poucos casos especiais que precisam ser feitos. Os casos especiais que existem são especificamente para lidar com o Win32 no Windows 3.1 (também conhecido como Win32s). O Win32s não suporta diretamente dados DLL por processo, portanto, o DLL Do MFC deve usar as APIs Win32 (Thread-Local Storage, armazenamento local de thread) para obter dados locais de processo.

### <a name="impact-on-library-sources-additional-files"></a>Impacto em fontes de biblioteca, arquivos adicionais

O impacto da versão **_AFXDLL** nas fontes normais de biblioteca de classe MFC e cabeçalhos é relativamente menor. Há um arquivo de versão especial (AFXV_DLL. H) bem como um arquivo de cabeçalho adicional (AFXDLL_. H) incluído pelo AFXWIN principal. Cabeçalho H. A AFXDLL_. O cabeçalho `CDynLinkLibrary` H inclui a `_AFXDLL` classe e outros detalhes de implementação de ambos os aplicativos e DLLs de extensão MFC. O AFXDLLX. H header é fornecido para a construção de DLLs de extensão MFC (veja acima para obter detalhes).

As fontes regulares da biblioteca MFC em MFC SRC `_AFXDLL` têm algum código condicional adicional sob o #ifdef. Um arquivo de origem adicional (DLLINIT. CPP) contém o código de inicialização dll extra e outra cola para a versão compartilhada do MFC.

Para construir a versão compartilhada do MFC, arquivos adicionais são fornecidos. (Veja abaixo detalhes sobre como construir o DLL.)

- Dois. Os arquivos DEF são usados para exportar os pontos de entrada do MFC DLL para versões de depuração (MFCxxD.DEF) e versão (MFCxx.DEF) das versões DLL.

- Um. Arquivo RC (MFCDLL. RC) contém todos os recursos padrão do MFC e um recurso VERSIONINFO para o DLL.

- Um. Arquivo CLW (MFCDLL. CLW) é fornecido para permitir a navegação nas classes MFC usando ClassWizard. Nota: este recurso não é particular à versão DLL do MFC.

### <a name="memory-management"></a>Gerenciamento de memória

Um aplicativo usando MFCxx.DLL usa um localizador de memória comum fornecido pelo MSVCRTxx.DLL, o DLL de tempo de execução C compartilhado. O aplicativo, qualquer DLLs de extensão MFC e os próprios DLLs do MFC usam este alocador de memória compartilhada. Usando um DLL compartilhado para alocação de memória, os DLLs do MFC podem alocar memória que é liberada posteriormente pelo aplicativo ou vice-versa. Como tanto o aplicativo quanto o DLL devem usar o mesmo alocador, você não deve substituir o operador global C++ **ou** **excluir o operador**global . As mesmas regras se aplicam ao resto das rotinas de alocação de memória em tempo de execução C (como **malloc**, **realloc,** **free,** e outros).

### <a name="ordinals-and-class-__declspecdllexport-and-dll-naming"></a>Ordinals e classe __declspec (dllexport) e nomeação DLL

Não usamos a `class` funcionalidade **__declspec (dllexport)** do compilador C++. Em vez disso, uma lista de exportações é incluída com as fontes de biblioteca de classe (MFCxx.DEF e MFCxxD.DEF). Apenas estes pontos de entrada selecionados (funções e dados) são exportados. Outros símbolos, como funções de implementação privada mfc ou classes, não são exportados Todas as exportações são feitas por ordinal sem um nome de seqüência na tabela de nomes residente ou não residente.

O `class` uso **de __declspec(dllexport)** pode ser uma alternativa viável para a construção de DLLs menores, mas no caso de uma DLL grande como a MFC, o mecanismo de exportação padrão tem limites de eficiência e capacidade.

O que tudo isso significa é que podemos embalar uma grande quantidade de funcionalidade na versão MFCxx.DLL que é apenas cerca de 800 KB sem comprometer muita execução ou velocidade de carregamento. MFCxx.DLL teria sido 100K maior se esta técnica não tivesse sido usada. Isso também permite adicionar pontos de entrada adicionais no final do . Arquivo DEF para permitir uma versão simples sem comprometer a velocidade e a eficiência de tamanho da exportação por ordinal. As principais revisões de versão na biblioteca de classes do MFC mudarão o nome da biblioteca. Ou seja, MFC30. DLL é o DLL redistributable contendo a versão 3.0 da biblioteca de classes MFC. Um upgrade desta DLL, digamos, em um Hipotético MFC 3.1, o DLL seria chamado DeMFC31. DLL em vez disso. Novamente, se você modificar o código fonte do MFC para produzir uma versão personalizada do MFC DLL, use um nome diferente (e de preferência um sem "MFC" no nome).

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
