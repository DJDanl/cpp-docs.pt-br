---
title: 'TN033: Versão DLL do MFC'
ms.date: 06/28/2018
f1_keywords:
- vc.mfc.dll
helpviewer_keywords:
- MFC DLLs [MFC], writing MFC extension DLLS
- AFXDLL library
- DLLs [MFC], MFC
- DLL version of MFC [MFC]
- TN033
ms.assetid: b6f1080b-b66b-4b1e-8fb1-926c5816392c
ms.openlocfilehash: 4bfc60e20a073dd34945b91dd48ba82cdf4ab9f3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62305535"
---
# <a name="tn033-dll-version-of-mfc"></a>TN033: Versão DLL do MFC

Essa observação descreve como você pode usar o compartilhadas e Mfcxxd (onde x é o número de versão do MFC) compartilhado bibliotecas de vínculo dinâmico com aplicativos do MFC e DLLs de extensão do MFC. Para obter mais informações sobre DLLs MFC regulares, consulte [usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md).

Essa observação técnica aborda três aspectos das DLLs. As duas últimas são para os usuários mais avançados:

- [Como criar uma DLL de extensão do MFC](#_mfcnotes_how_to_write_an_mfc_extension_dll)

- [Como criar um aplicativo do MFC que usa a versão DLL do MFC](#_mfcnotes_writing_an_application_that_uses_the_dll_version)

- [Como o MFC compartilhados bibliotecas de vínculo dinâmico são implementados](#_mfcnotes_how_the_mfc30.dll_is_implemented)

Se você estiver interessado na criação de uma DLL usando MFC que pode ser usado com aplicativos não MFC (Isso é chamado de uma DLL MFC regular), consulte [11 de observação técnica](../mfc/tn011-using-mfc-as-part-of-a-dll.md).

## <a name="overview-of-mfcxxdll-support-terminology-and-files"></a>Visão geral de suporte compartilhadas: Arquivos e terminologia

**DLL MFC regular**: Você pode usar uma DLL MFC regular para criar uma DLL autônomo usando algumas das classes MFC. Interfaces além do limite de aplicativo/DLL são interfaces de "C" e o aplicativo cliente não precisa ser um aplicativo do MFC.

Essa é a versão de suporte DLL com suporte no MFC 1.0. Ele é descrito em [11 de observação técnica](../mfc/tn011-using-mfc-as-part-of-a-dll.md) e o exemplo de conceitos avançados MFC [DLLScreenCap](../overview/visual-cpp-samples.md).

> [!NOTE]
> A partir do Visual C++ versão 4.0, o termo **USRDLL** está obsoleto e foi substituído por uma DLL MFC regular que vincula estaticamente ao MFC. Você também pode criar uma DLL do MFC que vincula dinamicamente ao MFC regular.

MFC 3.0 (ou superior) dá suporte a DLLs MFC regulares com todas as novas funcionalidades incluindo as classes de banco de dados OLE.

**AFXDLL**: Isso também é conhecido como a versão compartilhada das bibliotecas do MFC. Isso é o novo suporte DLL adicionado no MFC 2.0. A biblioteca do MFC em si está em um número de DLLs (descritos abaixo) e um aplicativo cliente ou DLL vincula dinamicamente as DLLs que ele exige. Interfaces além do limite da DLL do aplicativo/são C++/MFC interfaces de classe. O aplicativo cliente deve ser um aplicativo do MFC. Isso dá suporte a todas as funcionalidades de MFC 3.0 (exceção: UNICODE não há suporte para as classes de banco de dados).

> [!NOTE]
> A partir do Visual C++ versão 4.0, esse tipo de DLL é conhecido como uma "DLL de extensão."

Essa observação usará compartilhadas para fazer referência a todo o conjunto de DLL do MFC, que inclui:

- Depurar: Mfcxxd (combinados) e MFCSxxD.LIB (estático).

- Versão: Compartilhadas (combinados) e MFCSxx.LIB (estático).

- Depuração do Unicode: MFCxxUD.DLL (combinados) e MFCSxxD.LIB (estático).

- Versão do Unicode: MFCxxU.DLL (combinados) e MFCSxxU.LIB (estático).

> [!NOTE]
> O MFCSxx [U] [D]. Bibliotecas LIB são usadas em DLLs compartilhadas do conjunto com o MFC. Essas bibliotecas contêm código que deve ser vinculado estaticamente para o aplicativo ou DLL.

Bibliotecas de importação de um aplicativo é vinculado a correspondente:

- Depurar: MFCxxD.LIB

- Versão: MFCxx.LIB

- Depuração do Unicode: MFCxxUD.LIB

- Versão do Unicode: MFCxxU.LIB

Uma DLL de extensão"MFC" é uma DLL compilada em cima compartilhadas (e/ou a outra MFC compartilhado DLLs). Aqui a arquitetura de componente do MFC é acionado. Se você deriva uma classe útil de uma classe do MFC ou criar outro Kit de ferramentas do MFC semelhante, você pode colocá-lo em uma DLL. Que DLL usa compartilhadas, o aplicativo cliente ultimate. Isso permite que classes de folha reutilizável, classes base reutilizáveis e classes de exibição/documento reutilizáveis.

## <a name="pros-and-cons"></a>Prós e contras

Por que você deve usar a versão compartilhada do MFC

- Usando a biblioteca compartilhada pode resultar em aplicativos menores (um aplicativo mínimo que usa a maior parte da biblioteca MFC é menor que 10 mil).

- A versão compartilhada do MFC dá suporte a DLLs de extensão do MFC e DLLs MFC regulares.

- Criando um aplicativo que usa as bibliotecas MFC compartilhadas é mais rápido que compilar um aplicativo MFC vinculado estaticamente, pois não é necessário vincular o próprio MFC. Isso é especialmente verdadeiro no **depurar** compilações em que o vinculador deverá compactar as informações de depuração — por meio da vinculação com uma DLL que já contém as informações de depuração, há menos informações de depuração para compactar dentro de seu aplicativo.

Por que você não deve usar a versão compartilhada do MFC:

- Um aplicativo que usa a biblioteca compartilhada de envio exige que você enviar o compartilhadas (e outros) biblioteca com seu programa. Compartilhadas pode ser redistribuído, como muitas DLLs, mas você ainda deve instalar a DLL no seu programa de instalação. Além disso, você deve enviar MSVCRTxx.DLL, que contém a biblioteca de tempo de execução C que é usada pelo seu programa e as próprias DLLs MFC.

##  <a name="_mfcnotes_how_to_write_an_mfc_extension_dll"></a> Como escrever uma DLL de extensão do MFC

Uma DLL de extensão do MFC é uma DLL que contém classes e funções escritas para aprimorar a funcionalidade das classes MFC. Uma DLL de extensão do MFC usa as DLLs do MFC compartilhado da mesma forma que um aplicativo usa, com algumas considerações adicionais:

- O processo de compilação é semelhante à criação de um aplicativo que usa as bibliotecas compartilhadas do MFC com alguns adicionais do compilador e as opções do vinculador.

- Uma DLL de extensão do MFC não tem um `CWinApp`-classe derivada.

- Uma DLL de extensão de MFC deve fornecer um especial `DllMain`. O AppWizard fornece um `DllMain` função que você pode modificar.

- Uma DLL de extensão do MFC geralmente fornecerá uma rotina de inicialização para criar uma `CDynLinkLibrary` se a extensão MFC DLL deseja exportar `CRuntimeClass`es ou recursos para o aplicativo. Uma classe derivada de `CDynLinkLibrary` podem ser usados se os dados por aplicativo devem ser mantidos pela extensão de MFC DLL.

Essas considerações são descritas mais detalhadamente abaixo. Você também deve se referir ao exemplo de conceitos avançados MFC [DLLHUSK](../overview/visual-cpp-samples.md) , pois ele ilustra:

- Criando um aplicativo usando as bibliotecas compartilhadas. (DLLHUSK. EXE é um aplicativo do MFC que vincula dinamicamente às bibliotecas MFC, bem como outras DLLs.)

- Criando uma DLL de extensão do MFC. (Observe os sinalizadores especiais, como `_AFXEXT` que são usadas para criar uma DLL de extensão do MFC)

- Dois exemplos de DLLs de extensão do MFC. Mostra a estrutura básica de uma DLL de extensão do MFC com exportações limitadas (TESTDLL1) e outras mostra a exportação de uma interface de classe inteira (TESTDLL2).

O aplicativo cliente e quaisquer DLLs de extensão do MFC devem usar a mesma versão do compartilhadas. Você deve seguir a convenção de DLL do MFC e fornecer os dois de depuração e de varejo (/Release) versão do seu DLL de extensão do MFC. Isso permite que programas de cliente para criar versões de varejo e de depuração de seus aplicativos e vinculá-los com a versão de varejo de todas as DLLs ou de depuração apropriados.

> [!NOTE]
>  Como C++ a desconfiguração de nome e exportar problemas, a lista de exportação de uma extensão MFC DLL pode ser diferente entre as versões de depuração e de varejo da mesma DLL e DLLs para diferentes plataformas. A edição de varejo compartilhadas tem cerca de 2000 exportado pontos de entrada; a depuração Mfcxxd tem aproximadamente 3000 exportados pontos de entrada.

### <a name="quick-note-on-memory-management"></a>Observação rápida sobre o gerenciamento de memória

A seção intitulada "Gerenciamento de memória," perto do fim desta nota técnica, descreve a implementação do compartilhadas com a versão compartilhada do MFC. As informações que você precisa saber para implementar apenas uma extensão MFC que dll é descrita aqui.

Compartilhadas e todas as DLLs de extensão MFC carregadas no espaço de endereço de um aplicativo cliente usarão o mesmo alocador de memória, carregamento de recursos e outros estados "globais" do MFC como se estivessem no mesmo aplicativo. Isso é significativo porque as bibliotecas de DLL não MFC e DLLs MFC regulares vinculadas estaticamente ao MFC não o oposto exato e tem cada DLL alocando fora de seu próprio pool de memória.

Se uma DLL de extensão do MFC aloca memória, que a memória pode combinar livremente com qualquer outro objeto alocado pelo aplicativo. Além disso, se um aplicativo que usa as bibliotecas compartilhadas do MFC falhar, a proteção do sistema operacional manterá a integridade de qualquer outro aplicativo do MFC a DLL de compartilhamento.

Da mesma forma outros estados MFC "globais", como o atual arquivo executável para carregar recursos, também são compartilhados entre o aplicativo cliente e todas as DLLs de extensão do MFC, bem como compartilhadas em si.

### <a name="building-an-mfc-extension-dll"></a>Criação de uma DLL de extensão do MFC

Você pode usar o AppWizard para criar um projeto DLL de extensão do MFC, e ele irá gerar automaticamente o compilador apropriado e as configurações do vinculador. Ele foi também gerar um `DllMain` função que você pode modificar.

Se você estiver convertendo um projeto existente para uma DLL de extensão do MFC, começar com as regras padrão para a criação de um aplicativo usando a versão compartilhada do MFC e, em seguida, faça o seguinte:

- Adicione **/D_AFXEXT** aos sinalizadores de compilador. Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria de pré-processador. Adicionar `_AFXEXT` ao campo definir Macros, separando cada um dos itens com ponto e vírgula.

- Remover o **/Gy** comutador de compilador. Na caixa de diálogo Propriedades do projeto, selecione o nó C/C++. Em seguida, selecione a categoria de geração de código. Certifique-se de que a opção "Habilitar a vinculação do nível de função" não está habilitada. Isso tornará mais fácil exportar classes porque o vinculador não removerá as funções não referenciadas. Se o projeto original é usado para criar um regular DLL do MFC vinculadas estaticamente ao MFC, alterar o **/MT [d]** opção de compilador para **/MD [d]**.

- Criar uma biblioteca de exportação com o **/DLL** opção para LINK. Isso será definido quando você cria um novo destino, especificando a biblioteca de vínculo dinâmico do Win32 como o tipo de destino.

### <a name="changing-your-header-files"></a>Alterando os arquivos de cabeçalho

O objetivo de uma DLL de extensão do MFC geralmente é exportar alguma funcionalidade comum para um ou mais aplicativos que podem usar essa funcionalidade. Isso se resume à exportação de classes e funções globais que estão disponíveis para seus aplicativos cliente.

Para fazer isso, você deve garantir que cada uma das funções de membro é marcada como importar ou exportar conforme apropriado. Isso requer as declarações especiais: `__declspec(dllexport)` e `__declspec(dllimport)`. Quando suas classes são usadas pelos aplicativos cliente, você deseja que seja declarado como `__declspec(dllimport)`. Quando a própria DLL de extensão do MFC está sendo compilado, eles devem ser declarados como `__declspec(dllexport)`. Além disso, as funções devem ser exportadas de fato, para que os programas cliente vinculá-las em tempo de carregamento.

Para exportar sua classe inteira, use `AFX_EXT_CLASS` na definição de classe. Essa macro é definida pela estrutura como `__declspec(dllexport)` quando `_AFXDLL` e `_AFXEXT` é definida, mas definida como `__declspec(dllimport)` quando `_AFXEXT` não está definido. `_AFXEXT` conforme descrito acima, só é definido ao criar sua DLL de extensão do MFC. Por exemplo:

```cpp
class AFX_EXT_CLASS CExampleExport : public CObject
{ /* ... class definition ... */ };
```

### <a name="not-exporting-the-entire-class"></a>Não exportar a classe inteira

Às vezes, você talvez queira exportar apenas os membros individuais necessários da sua classe. Por exemplo, se você estiver exportando um `CDialog`-derivado da classe, você só precisará exportar o construtor e o `DoModal` chamar. Você pode exportar esses membros usando a DLL. Arquivo DEF, mas você também pode usar `AFX_EXT_CLASS` da mesma maneira em que os membros individuais, você precisa exportar.

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

Quando você fizer isso, você poderá encontrar um problema adicional porque você não estiver exportando todos os membros da classe. O problema é a maneira que funcionam de macros do MFC. Na verdade, várias das macros de auxiliares do MFC declararam ou definem membros de dados. Portanto, esses membros de dados também precisará ser exportados de sua DLL.

Por exemplo, a macro DECLARE_DYNAMIC é definida da seguinte maneira ao compilar uma DLL de extensão do MFC:

```cpp
#define DECLARE_DYNAMIC(class_name) \
protected: \
    static CRuntimeClass* PASCAL _GetBaseClass(); \
    public: \
    static AFX_DATA CRuntimeClass class##class_name; \
    virtual CRuntimeClass* GetRuntimeClass() const; \
```

A linha que começa "estático `AFX_DATA`" está declarando um objeto estático dentro de sua classe. Para exportar essa classe corretamente e acessar as informações de tempo de execução de um cliente. EXE, você precisa exportar este objeto estático. Porque o objeto estático é declarado com o modificador `AFX_DATA`, você só precisa definir `AFX_DATA` ser `__declspec(dllexport)` ao criar sua DLL e defini-lo como `__declspec(dllimport)` ao criar o executável do cliente.

Como discutido acima, `AFX_EXT_CLASS` já está definida dessa maneira. Você só precisa definir novamente `AFX_DATA` para ser o mesmo que `AFX_EXT_CLASS` em torno de sua definição de classe.

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

MFC sempre usa o `AFX_DATA` símbolo em itens de dados define em suas macros, portanto, essa técnica funcionará para todos esses cenários. Por exemplo, ele funcionará para DECLARE_MESSAGE_MAP.

> [!NOTE]
> Se você estiver exportando a classe inteira em vez de membros selecionados da classe, membros de dados estáticos são exportados automaticamente.

Você pode usar a mesma técnica para exportar automaticamente o `CArchive` operador de extração para classes que usam as macros DECLARE_SERIAL e IMPLEMENT_SERIAL. Exportar o operador de arquivo morto por colchetes as declarações de classe (localizado na. Arquivo do H) com o código a seguir:

```cpp
#undef AFX_API
#define AFX_API AFX_EXT_CLASS

/* your class declarations here */

#undef AFX_API
#define AFX_API
```

### <a name="limitations-of-afxext"></a>Limitações de _AFXEXT

Você pode usar o _**AFXEXT** símbolos de pré-processador para a sua extensão MFC DLLs, desde que você não tenha várias camadas de DLLs de extensão do MFC. Se você tiver a extensão de MFC que chame ou derivar de classes em sua própria extensão MFC DLLs, que derivam, em seguida, as classes MFC, você deve usar seu próprio símbolo do pré-processador para evitar ambiguidade.

O problema é que no Win32, você deve declarar explicitamente todos os dados como `__declspec(dllexport)` se ele deve ser exportada de uma DLL, e `__declspec(dllimport)` se for a serem importados de uma DLL. Quando você define `_AFXEXT`, os cabeçalhos MFC ter certeza de que `AFX_EXT_CLASS` está definido corretamente.

Quando você tem várias camadas, um símbolo, como `AFX_EXT_CLASS` não é suficiente, uma vez que uma DLL de extensão do MFC pode ser exportando novas classes bem como importar outras classes de outra extensão MFC DLL. Para lidar com esse problema, use um símbolo do pré-processador especial que indica que você está criando a DLL em vez de usar a DLL. Por exemplo, imagine que duas DLLs de extensão do MFC,. dll e b. dll. Cada um deles exportar algumas classes no A.H e B.H, respectivamente. B. dll usa as classes da dll. Os arquivos de cabeçalho seria algo parecido com isto:

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

Quando é compilado. dll, ele é compilado com **/DA_IMPL** e quando b. dll é compilado, ele é compilado com **/DB_IMPL**. Usando símbolos separados para cada DLL CExampleB é exportado e CExampleA é importado durante a criação de b. dll. CExampleA for exportado ao compilar a dll e importado quando usado por b. dll (ou outro cliente).

Esse tipo de disposição em camadas não pode ser feito ao usar o interno `AFX_EXT_CLASS` e `_AFXEXT` símbolos do pré-processador. A técnica descrita acima resolve esse problema de maneira diferente não que o mecanismo próprio MFC usa ao criar suas DLLs de extensão OLE, o banco de dados e o MFC de rede.

### <a name="not-exporting-the-entire-class"></a>Não exportar a classe inteira

Novamente, você precisa tomar cuidado especial quando você não estiver exportando uma classe inteira. Você precisará garantir que os itens de dados necessários criados pelas macros MFC são exportados corretamente. Isso pode ser feito definindo novamente `AFX_DATA` a macro de sua classe específica. Isso deve ser feito a qualquer momento que você não estiver exportando a classe inteira.

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

A seguir está o código exato que você deve colocar no seu arquivo de origem principal para a sua extensão MFC DLL. Ele deve vir depois que o padrão inclui. Observe que, quando você usa o AppWizard para criar os arquivos iniciais de uma DLL de extensão do MFC, ele fornece um `DllMain` para você.

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

A chamada para `AfxInitExtensionModule` captura as classes de tempo de execução de módulos (`CRuntimeClass` estruturas), bem como suas fábricas de objeto (`COleObjectFactory` objetos) para uso posteriormente, quando o `CDynLinkLibrary` objeto é criado. A chamada (opcional) para `AfxTermExtensionModule` permite MFC para limpar a DLL de extensão do MFC quando cada processo desanexa (o que ocorre quando o processo é encerrado ou quando a DLL é descarregada como resultado de uma `FreeLibrary` chamar) da extensão de MFC DLL. Desde a extensão MFC a maioria das DLLs não carregadas dinamicamente (geralmente, eles estão vinculados por meio de suas bibliotecas de importação), a chamada para `AfxTermExtensionModule` geralmente não é necessário.

Se seu aplicativo carrega e libera a extensão de MFC dinamicamente, certifique-se de chamar `AfxTermExtensionModule` conforme mostrado acima. Também não se esqueça de usar `AfxLoadLibrary` e `AfxFreeLibrary` (em vez de funções do Win32 `LoadLibrary` e `FreeLibrary`) se seu aplicativo usa vários threads ou se ele é carregado dinamicamente uma DLL de extensão do MFC. Usando o `AfxLoadLibrary` e `AfxFreeLibrary` assegura que o código de inicialização e desligamento é executado quando a DLL de extensão do MFC é carregado e descarregado não corromper o estado global do MFC.

O arquivo de cabeçalho AFXDLLX. H contém definições especiais para estruturas usadas em DLLs de extensão do MFC, como a definição para `AFX_EXTENSION_MODULE` e `CDynLinkLibrary`.

Global *extensionDLL* deve ser declarada como mostrado. Ao contrário da versão de 16 bits do MFC, você pode alocar memória e chamar funções MFC durante esse tempo, uma vez que o compartilhadas está totalmente inicializado no momento em seu `DllMain` é chamado.

### <a name="sharing-resources-and-classes"></a>Compartilhamento de recursos e Classes

DLLs de extensão MFC simples só precisam exportar algumas funções de baixa largura de banda para o aplicativo cliente e nada mais. Mais DLLs com uso intensivo de interface do usuário talvez queira exportar recursos e classes do C++ para o aplicativo cliente.

Exportando recursos é feito por meio de uma lista de recursos. Em cada aplicativo é uma lista individualmente vinculada de `CDynLinkLibrary` objetos. Quando você está procurando um recurso, a maioria das implementações padrão do MFC que carregar recursos ver primeira módulo de recursos atual (`AfxGetResourceHandle`) e, se não encontrar o exame de lista de `CDynLinkLibrary` objetos tentar carregar o recurso solicitado.

Criação dinâmica de objetos de C++ que recebe um nome de classe do C++ é semelhante. O mecanismo de desserialização do objeto MFC precisa ter todos os `CRuntimeClass` objetos registrados para que ele pode reconstruir criando dinamicamente o objeto de C++ do tipo necessário com base no que foi armazenado anteriormente.

Se você quiser que o aplicativo cliente para usar as classes que estão em sua extensão MFC DLL `DECLARE_SERIAL`, em seguida, você precisará exportar suas classes sejam visíveis para o aplicativo cliente. Isso também é feito inserindo a `CDynLinkLibrary` lista.

No caso do exemplo de conceitos avançados MFC [DLLHUSK](../overview/visual-cpp-samples.md), a lista se parece com:

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

O compartilhadas é geralmente último na lista de classes e recursos. Compartilhadas inclui todos os recursos padrão do MFC, incluindo cadeias de caracteres de prompt para todas as IDs de comando padrão. Permite a colocando-o ao final da lista de DLLs e o aplicativo cliente em si não tenha um sua própria cópia dos recursos MFC padrão, mas ao contar com os recursos compartilhados no compartilhadas em vez disso.

Mesclando os recursos e nomes de classe de todas as DLLs de espaço para nome do aplicativo cliente tem a desvantagem de que você precisa ter cuidado quais IDs ou nomes que você escolher. Você pode certamente desabilitar esse recurso por meio da exportação não qualquer um os recursos ou um `CDynLinkLibrary` objeto para o aplicativo cliente. O [DLLHUSK](../overview/visual-cpp-samples.md) exemplo gerencia o espaço de nome de recurso compartilhado por meio de vários arquivos de cabeçalho. Ver [35 de observação técnica](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md) para obter mais dicas sobre como usar arquivos de recurso compartilhado.

### <a name="initializing-the-dll"></a>Inicializar a DLL

Conforme mencionado acima, você geralmente deseja criar um `CDynLinkLibrary` objeto para exportar seus recursos e classes para o aplicativo cliente. Você precisará fornecer um ponto de entrada exportado para inicializar a DLL. No mínimo, isso é uma rotina de void que não leva argumentos e não retorna nada, mas ele pode ser qualquer coisa que você deseja.

Cada aplicativo cliente que deseja usar sua DLL deve chamar essa rotina de inicialização, se você usar essa abordagem. Isso também pode alocar `CDynLinkLibrary` do objeto em seu `DllMain` depois de chamar `AfxInitExtensionModule`.

A rotina de inicialização deve criar um `CDynLinkLibrary` objeto no heap do aplicativo atual, vinculei sua informações de DLL de extensão do MFC. Isso pode ser feito com o seguinte:

```cpp
extern "C" extern void WINAPI InitXxxDLL()
{
    new CDynLinkLibrary(extensionDLL);
}
```

O nome da rotina *InitXxxDLL* neste exemplo, pode ser qualquer coisa que você deseja. Ele não precisa ser **extern "C"**, mas fazendo assim torna mais fácil de manter a lista de exportação.

> [!NOTE]
> Se você usar sua DLL de extensão MFC de uma DLL MFC regular, você deve exportar a função de inicialização. Essa função deve ser chamada de DLL do MFC normal antes de usar quaisquer classes DLL de extensão do MFC ou recursos.

### <a name="exporting-entries"></a>Exportar entradas

A maneira simple de exportar suas classes é usar `__declspec(dllimport)` e `__declspec(dllexport)` em cada classe e a função global que você deseja exportar. Isso torna muito mais fácil, mas é menos eficiente do que cada ponto de entrada (descrito abaixo) de nomenclatura, já que você tem menos controle sobre quais funções são exportadas e você não pode exportar as funções por ordinal. TESTDLL1 e TESTDLL2 usam esse método para exportar suas entradas.

Um método mais eficiente (e o método usado pelo compartilhadas) é exportar cada entrada de mão ao nomear cada entrada na. Arquivo DEF. Uma vez que estamos esteja exportando seletivas exportações de nossa DLL (ou seja, nem tudo), devemos decidir quais interfaces específicos que deseja exportar. Isso é difícil, pois você deve especificar os nomes danificados para o vinculador na forma de entradas na. Arquivo DEF. Não exporte a quaisquer classes C++, a menos que você realmente precisa ter um link simbólico para ele.

Se você tiver tentado exportar C++ classes com um. Antes, talvez você queira desenvolver uma ferramenta para gerar essa lista automaticamente do arquivo DEF. Isso pode ser feito usando um processo de link de dois estágios. Vincular seu DLL, uma vez com nenhuma exportação e permitir que o vinculador gerar um. Arquivo de mapa. A. Arquivo de mapa pode ser usado para gerar uma lista de funções que devem ser exportados, portanto, com algumas reorganizar, ele pode ser usado para gerar as entradas de exportação para o. Arquivo DEF. A lista de exportação para compartilhadas e o OLE e DLLs de extensão de MFC de banco de dados, vários milhares em número, foi gerada com tal processo (embora ele não é totalmente automático e exige algum ajuste de vez em quando de mão).

### <a name="cwinapp-vs-cdynlinklibrary"></a>CWinApp vs. CDynLinkLibrary

Uma DLL de extensão do MFC não tem um `CWinApp`-objeto próprio derivado; em vez disso, ele deve funcionar com o `CWinApp`-objeto do aplicativo cliente derivado. Isso significa que o aplicativo cliente que detém a bomba de mensagem principal, o loop ocioso e assim por diante.

Se sua extensão de MFC DLL precisa manter dados extras para cada aplicativo, você pode derivar uma nova classe de `CDynLinkLibrary` e criá-lo no InitXxxDLL rotina descrito acima. Quando em execução, a DLL pode verificar a lista do aplicativo atual de `CDynLinkLibrary` objetos para localizar o item para essa extensão MFC DLL específico.

### <a name="using-resources-in-your-dll-implementation"></a>Uso de recursos em sua implementação de DLL

Conforme mencionado acima, a carga de recursos padrão orientará a lista de `CDynLinkLibrary` objetos procurando primeiro EXE ou DLL que tem o recurso solicitado. Todas as APIs de MFC assim como todos o código interno usa `AfxFindResourceHandle` para percorrer a lista de recursos para localizar qualquer recurso, não importa onde ele pode residir.

Se você quiser carregar apenas os recursos de um local específico, use as APIs `AfxGetResourceHandle` e `AfxSetResourceHandle` para salvar o antigo identificador e definir o novo identificador. Certifique-se de restaurar o antigo identificador do recurso antes de retornar para o aplicativo cliente. O exemplo TESTDLL2 usa essa abordagem para carregar explicitamente um menu.

Percorrer a lista tem as desvantagens que ele é um pouco mais lento e requer o gerenciamento de intervalos de ID de recurso. Ele tem a vantagem de que um aplicativo cliente que contém links para várias DLLs de extensão MFC pode usar qualquer recurso fornecido pelo DLL sem ter que especificar o identificador de instância DLL. `AfxFindResourceHandle` é uma API usada para percorrer a lista de recursos para procurar uma correspondência de determinado. Ele usa o nome e um tipo de recurso e retorna o identificador de recurso em que foi encontrada pela primeira vez (ou nulo).

##  <a name="_mfcnotes_writing_an_application_that_uses_the_dll_version"></a> Escrevendo um aplicativo que usa a versão DLL

### <a name="application-requirements"></a>Requisitos do aplicativo

Um aplicativo que usa a versão compartilhada do MFC deve seguir algumas regras simples:

- Ele deve ter um `CWinApp` do objeto e seguem as regras padrão para uma bomba de mensagem.

- Ele deve ser compilado com um conjunto de sinalizadores de compilador necessária (veja abaixo).

- Ele deve vincular com as bibliotecas de importação MFCxx. Definindo os sinalizadores de compilador necessária, os cabeçalhos MFC determinam no tempo de vinculação qual biblioteca o aplicativo deve vincular com.

- Para executar o executável, compartilhadas deve ser no caminho ou no diretório do sistema Windows.

### <a name="building-with-the-development-environment"></a>Compilando com o ambiente de desenvolvimento

Se você estiver usando o makefile interno com a maioria dos padrões standard, você pode alterar facilmente o projeto para compilar a versão DLL.

A etapa a seguir pressupõe que você tiver um aplicativo MFC funcionar corretamente vinculado com NAFXCWD. LIB (para depuração) e NAFXCW. LIB (para o varejo) e deseja convertê-lo para usar a versão compartilhada da biblioteca MFC. Você estiver executando o ambiente do Visual C++ e tem um arquivo de projeto interno.

1. Sobre o **projetos** menu, clique em **propriedades**. No **gerais** página sob **padrões de projeto**, defina Microsoft Foundation Classes como **usar MFC em uma DLL compartilhada** (MFCxx(d).dll).

### <a name="building-with-nmake"></a>Compilando com NMAKE

Se você estiver usando o recurso externo makefile do Visual C++, ou estiver usando NMAKE diretamente, você terá que editar o makefile para dar suporte a compilador e as opções do vinculador

Sinalizadores de compilador necessária:

- **/D_AFXDLL /MD**
   **/D_AFXDLL**

Os cabeçalhos padrão do MFC precisam desse símbolo seja definido:

- **/MD** o aplicativo deve usar a versão DLL da biblioteca em tempo de execução C

Todos os outros sinalizadores de compilador seguirão os padrões MFC (por exemplo, Debug para depuração).

Edite a lista de vinculador de bibliotecas. Alteração NAFXCWD. LIB para MFCxxD.LIB e altere NAFXCW. LIB para MFCxx.LIB. Substitua LIBC. LIB com MSVCRT. LIB. Como com qualquer outra biblioteca MFC, é importante que MFCxxD.LIB é colocado **antes de** quaisquer bibliotecas de tempo de execução C.

Opcionalmente, adicione **/D_AFXDLL** opções do compilador de recurso seu comerciais e depuração (aquele que compila, na verdade, os recursos com **/R**). Isso torna seu arquivo executável final menor, compartilham os recursos que estão presentes em DLLs do MFC.

Uma recompilação completa é necessária depois que essas alterações forem feitas.

### <a name="building-the-samples"></a>Compilando os exemplos

A maioria dos programas de exemplo do MFC pode ser criada do Visual C++ ou de um MAKEFILE NMAKE compatível compartilhado da linha de comando.

Para converter qualquer um desses exemplos Use compartilhadas, você pode carregar o. MAK de arquivos do Visual c++ e defina as opções de projeto, conforme descrito acima. Se você estiver usando a compilação NMAKE, você pode especificar "AFXDLL = 1" NMAKE, a linha de comando e que será compilar o exemplo usando as bibliotecas compartilhadas do MFC.

O exemplo de conceitos avançados MFC [DLLHUSK](../overview/visual-cpp-samples.md) é criado com a versão DLL do MFC. Não apenas, este exemplo ilustra como criar um aplicativo vinculado com compartilhadas, mas ele também ilustra a outros recursos da opção de empacotamento de DLL do MFC, como descrito mais adiante neste nota técnica de DLLs de extensão de MFC.

### <a name="packaging-notes"></a>Notas de empacotamento

A versão comercial das DLLs (MFCxx [U]. DLL) são livremente redistribuíveis. A versão de depuração das DLLs não são livremente redistribuível e deve ser usado somente durante o desenvolvimento de seu aplicativo.

A depuração de DLLs são fornecidas com as informações de depuração. Usando o depurador do Visual C++, você pode rastrear a execução de seu aplicativo, bem como a DLL. As DLLs de versão (MFCxx [U]. DLL) não contêm informações de depuração.

Se você personaliza ou recriar as DLLs, em seguida, você deve chamá-los algo diferente de arquivo "MFCxx" o MFC SRC MFCDLL. MAK descreve as opções de compilação e contém a lógica para renomear a DLL. Renomear os arquivos é necessária, já que essas DLLs são potencialmente compartilhadas por muitos aplicativos MFC. Ter sua versão personalizada do substituir DLLs MFC estiverem instalados no sistema podem interromper o outro aplicativo do MFC usando DLLs do MFC compartilhado.

Não é recomendável recriar as DLLs do MFC.

##  <a name="_mfcnotes_how_the_mfc30.dll_is_implemented"></a> Como o compartilhadas é implementado

A seção a seguir descreve como a DLL do MFC (compartilhadas e Mfcxxd) é implementada. Noções básicas sobre que os detalhes aqui também não são importantes se tudo o que você deseja fazer é usar a DLL do MFC com o aplicativo. Os detalhes aqui não são essenciais para compreender como escrever uma DLL de extensão do MFC, mas entender essa implementação pode ajudá-lo a escrever sua própria DLL.

### <a name="implementation-overview"></a>Visão geral da implementação

A DLL do MFC é realmente um caso especial de uma DLL de extensão do MFC, conforme descrito acima. Ele tem um número muito grande de exportações para um grande número de classes. Há algumas coisas adicionais fazemos na DLL do MFC que facilitam ainda mais especiais que uma extensão MFC regular DLL.

### <a name="win32-does-most-of-the-work"></a>Win32 faz a maior parte do trabalho

A versão de 16 bits do MFC necessárias várias técnicas especiais, incluindo dados por aplicativo no segmento de pilha, segmentos especiais criados por um código de 80x86 assembly, contextos de exceção por processo e outras técnicas. Win32 diretamente dá suporte a dados de cada processo em uma DLL, que é o que você deseja que a maioria das vezes. Na maior parte compartilhadas é apenas NAFXCW. LIB empacotado em uma DLL. Se você examinar o código-fonte MFC, você encontrará _AFXDLL #ifdef muito poucos, já que há muito poucos casos especiais que precisam ser feitas. Os casos especiais que são há especificamente para lidar com o Win32 no 3.1 do Windows (também conhecido como Win32s). Win32s faz não suporte por processo DLL dados diretamente, portanto, a DLL do MFC deve usar o armazenamento local de thread (TLS) as APIs do Win32 para obter dados de processo local.

### <a name="impact-on-library-sources-additional-files"></a>Impacto na fonte de bibliotecas, arquivos adicionais

O impacto do **_AFXDLL** versão na fonte de bibliotecas de classe do MFC e cabeçalhos normal é relativamente pequena. Há uma versão especial do arquivo (AFXV_DLL. H), bem como um arquivo de cabeçalho adicionais (AFXDLL_. H) incluído por AFXWIN o principal. Cabeçalho de H. AFXDLL_. Cabeçalho de H inclui o `CDynLinkLibrary` classe e outros detalhes de implementação de ambos `_AFXDLL` aplicativos e DLLs de extensão do MFC. AFXDLLX. Cabeçalho de H é fornecido para a criação de DLLs de extensão de MFC (consulte acima para obter detalhes).

Fontes de regular para a biblioteca do MFC no MFC SRC tem algum código condicional adicional sob o `_AFXDLL` #ifdef. Um arquivo de origem adicionais (DLLINIT. CPP) contém o código de inicialização de DLL extra e outra liga para a versão compartilhada do MFC.

A fim de criar a versão compartilhada do MFC, arquivos adicionais são fornecidos. (Consulte abaixo para obter detalhes sobre como criar a DLL).

- Dois. Arquivos DEF são usados para exportar os pontos de entrada de DLL do MFC para depuração (MFCxxD.DEF) e release (MFCxx.DEF) versões da DLL.

- Um arquivo. Arquivo RC (MFCDLL. RC) contém todos os recursos padrão do MFC e um recurso VERSIONINFO para a DLL.

- A. Arquivo CLW (MFCDLL. CLW) é fornecido permitir a navegação de MFC de classes usando ClassWizard. Observação: esse recurso não é específico para a versão DLL do MFC.

### <a name="memory-management"></a>Gerenciamento de memória

Um aplicativo usando compartilhadas usa um alocador de memória comum fornecido pelo MSVCRTxx.DLL, a DLL compartilhada de tempo de execução C. O aplicativo, quaisquer DLLs de extensão do MFC e bem como as próprias DLLs MFC usam esse alocador de memória compartilhada. Ao usar uma DLL compartilhada para alocação de memória, as DLLs do MFC pode alocar memória liberada posteriormente pelo aplicativo ou vice-versa. Como o aplicativo e a DLL devem usar o mesmo alocador, você não deve substituir o C++ global **operador new** ou **operador delete**. As mesmas regras se aplicam ao resto das rotinas de alocação de memória de tempo de execução C (como **malloc**, **realloc**, **livre**e outros).

### <a name="ordinals-and-class-declspecdllexport-and-dll-naming"></a>Ordinais e classe dllexport e nomenclatura de DLL

Não usamos a `class` **dllexport** funcionalidade do C++ compilador. Em vez disso, uma lista de exportações é incluída com as fontes de biblioteca de classe (MFCxx.DEF e MFCxxD.DEF). Apenas esses selecione conjunto de pontos de entrada (dados e funções) são exportados. Não são exportados outros símbolos, como funções de implementação privada do MFC ou classes, todas as exportações são feitas pelo ordinal sem um nome de cadeia de caracteres na tabela de nomes residentes ou não residente.

Usando o `class` **dllexport** pode ser uma alternativa viável para a criação de DLLs menores, mas no caso de uma DLL grande, como o MFC, o padrão de exportação de mecanismo tem capacidade e eficiência de limites.

O que isso tudo significa é que podemos pode uma grande quantidade de recursos da versão compartilhadas é apenas cerca de 800 KB sem comprometer muito execução ou velocidade de carregamento do pacote. Compartilhadas teria sido 100 mil maiores essa técnica não tivesse sido usado. Isso também torna possível adicionar pontos de entrada adicionais no final da. Arquivo DEF para permitir que o controle de versão simple sem comprometer a eficiência de velocidade e tamanho de exportação por ordinal. Revisões de versão principal da biblioteca de classes MFC alterará o nome da biblioteca. Ou seja, MFC30. DLL é redistribuível DLL que contém a versão 3.0 da biblioteca de classes do MFC. Uma atualização dessa dll, digamos, em um 3.1 hipotético do MFC, a DLL será nomeada MFC31. DLL em vez disso. Novamente, se você modificar o código-fonte MFC para produzir uma versão personalizada da DLL da MFC, use um nome diferente (e preferencialmente um sem "MFC" no nome).

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
