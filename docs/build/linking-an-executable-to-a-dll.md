---
title: Vincular um executável a uma DLL
ms.date: 11/04/2016
helpviewer_keywords:
- run time [C++], linking
- dynamic load linking [C++]
- linking [C++], DLLs
- DLLs [C++], linking
- implicit linking [C++]
- explicit linking [C++]
- executable files [C++], linking to DLLs
- loading DLLs [C++]
ms.assetid: 7592e276-dd6e-4a74-90c8-e1ee35598ea3
ms.openlocfilehash: c4f9ea7a3606612189e85401b75a0577896fd90e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493219"
---
# <a name="link-an-executable-to-a-dll"></a>Vincular um executável a uma DLL

Um arquivo executável vincula (ou carrega) uma DLL de uma das duas maneiras:

- *Vinculação implícita*, em que o sistema operacional carrega a dll quando o executável que a usa é carregado. O executável do cliente chama as funções exportadas da DLL da mesma forma como se as funções estivessem vinculadas estaticamente e estão contidas no executável. A vinculação implícita às vezes é chamada de *carga estática* ou *vinculação dinâmica de tempo de carregamento*.

- *Vinculação explícita*, em que o sistema operacional carrega a dll sob demanda no tempo de execução. Um executável que usa uma DLL por vinculação explícita deve fazer chamadas de função para carregar e descarregar explicitamente a DLL e acessar as funções exportadas pela DLL. Ao contrário de chamadas para funções em uma biblioteca vinculada estaticamente, o executável do cliente deve chamar as funções exportadas em uma DLL por meio de um ponteiro de função. A vinculação explícita é, às vezes, chamada de *carregamento* dinâmico ou *vinculação dinâmica em tempo de execução*.

Um executável pode usar o método de vinculação para vincular ao mesmo DLL. Além disso, esses métodos não são mutuamente exclusivos; um executável pode vincular implicitamente a uma DLL e outra pode anexá-la explicitamente.

<a name="determining-which-linking-method-to-use"></a>

## <a name="link-an-executable-to-a-dll"></a>Vincular um executável a uma DLL

A possibilidade de usar vinculação implícita ou vinculação explícita é uma decisão arquitetônica que você deve fazer para seu aplicativo. Há vantagens e desvantagens em cada método.

### <a name="implicit-linking"></a>Vinculação implícita

A vinculação implícita ocorre quando o código de um aplicativo chama uma função DLL exportada. Quando o código-fonte para o executável de chamada é compilado ou montado, a chamada de função de DLL gera uma referência de função externa no código do objeto. Para resolver essa referência externa, o aplicativo deve vincular com a biblioteca de importação (arquivo. lib) fornecida pelo criador da DLL.

A biblioteca de importação contém apenas o código para carregar a DLL e implementar chamadas para funções na DLL. A localização de uma função externa em uma biblioteca de importação informa ao vinculador que o código para essa função está em uma DLL. Para resolver referências externas a DLLs, o vinculador simplesmente adiciona informações ao arquivo executável que informa ao sistema onde encontrar o código DLL quando o processo é iniciado.

Quando o sistema inicia um programa que contém referências vinculadas dinamicamente, ele usa as informações no arquivo executável do programa para localizar as DLLs necessárias. Se não for possível localizar a DLL, o sistema encerrará o processo e exibirá uma caixa de diálogo que relata o erro. Caso contrário, o sistema mapeia os módulos de DLL para o espaço de endereço do processo.

Se qualquer uma das DLLs tiver uma função de ponto de entrada para o código `DllMain`de inicialização e término, como, o sistema operacional chamará a função. Um dos parâmetros passados para a função de ponto de entrada especifica um código que indica que a DLL está anexando ao processo. Se a função de ponto de entrada não retornar TRUE, o sistema encerrará o processo e relatará o erro.

Por fim, o sistema modifica o código executável do processo para fornecer endereços iniciais para as funções de DLL.

Como o restante do código de um programa, o código de DLL é mapeado para o espaço de endereço do processo quando o processo é iniciado e é carregado na memória somente quando necessário. Como resultado, os `PRELOAD` atributos de código e `LOADONCALL` usados por arquivos. def para controlar o carregamento em versões anteriores do Windows não têm mais significado.

### <a name="explicit-linking"></a>Vinculação explícita

A maioria dos aplicativos usa vinculação implícita porque é o método de vinculação mais fácil de usar. No entanto, há ocasiões em que a vinculação explícita é necessária. Aqui estão alguns motivos comuns para usar a vinculação explícita:

- O aplicativo não sabe o nome de uma DLL que ele carrega até o tempo de execução. Por exemplo, o aplicativo pode obter o nome da DLL e as funções exportadas de um arquivo de configuração na inicialização.

- Um processo que usa vinculação implícita é encerrado pelo sistema operacional se a DLL não for encontrada na inicialização do processo. Um processo que usa vinculação explícita não é encerrado nessa situação e pode tentar se recuperar do erro. Por exemplo, o processo poderia notificar o usuário sobre o erro e fazer com que o usuário especifique outro caminho para a DLL.

- Um processo que usa vinculação implícita também será encerrado se qualquer uma das DLLs a que estiver vinculada `DllMain` tiver uma função que falha. Um processo que usa vinculação explícita não é encerrado nessa situação.

- Um aplicativo que implicitamente vincula a várias DLLs pode ser lento para iniciar porque o Windows carrega todas as DLLs quando o aplicativo é carregado. Para melhorar o desempenho de inicialização, um aplicativo pode vincular implicitamente apenas a essas DLLs necessárias imediatamente após o carregamento e aguardar até que outras DLLs sejam necessárias para vinculá-las explicitamente.

- A vinculação explícita elimina a necessidade de vincular o aplicativo usando uma biblioteca de importação. Se as alterações na DLL fizerem a alteração dos ordinais de exportação, os aplicativos que usam vinculação explícita não precisarão vincular novamente se chamarem `GetProcAddress` usando o nome de uma função e não um valor ordinal, enquanto os aplicativos que usam vinculação implícita devem vincular novamente ao nova biblioteca de importação.

Aqui estão dois perigos de vinculação explícita a serem cientes de:

- Se a DLL tiver uma `DllMain` função de ponto de entrada, o sistema operacional chamará a função no contexto do thread que `LoadLibrary`chamou. A função de ponto de entrada não será chamada se a dll já estiver anexada ao processo devido a uma chamada anterior `LoadLibrary` a que não tinha nenhuma chamada correspondente `FreeLibrary` à função. A vinculação explícita pode causar problemas se a dll usar `DllMain` uma função para executar a inicialização para cada thread de um processo, pois os threads que `AfxLoadLibrary`já existem quando `LoadLibrary` (ou) são chamados não são inicializados.

- Se uma DLL declarar dados de extensão estática como `__declspec(thread)`, ela poderá causar uma falha de proteção se vinculada explicitamente. Depois que a DLL for carregada por uma chamada `LoadLibrary`para, ela causará uma falha de proteção sempre que o código fizer referência a esses dados. (Os dados de extensão estática incluem itens estáticos globais e locais.) Portanto, ao criar uma DLL, você deve evitar usar o armazenamento local de thread ou informar aos usuários DLL sobre as possíveis armadilhas de carregar dinamicamente sua DLL. Para obter mais informações, consulte [usando o armazenamento local de thread em uma biblioteca de vínculo dinâmico (SDK do Windows)](/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

<a name="linking-implicitly"></a>

## <a name="link-an-executable-to-a-dll"></a>Vincular um executável a uma DLL

Para usar uma DLL por vinculação implícita, os executáveis do cliente devem obter esses arquivos do provedor da DLL:

- Um ou mais arquivos de cabeçalho (arquivos. h) que contêm as declarações dos dados exportados, funções e C++ /ou classes na dll. As classes, as funções e os dados exportados pela dll devem ser `__declspec(dllimport)` marcados no arquivo de cabeçalho. Para saber mais, confira [dllexport, dllimport](../cpp/dllexport-dllimport.md).

- Uma biblioteca de importação para vincular ao seu executável. O vinculador cria a biblioteca de importação quando a DLL é criada. Para obter mais informações, consulte [. Arquivos LIB](reference/dot-lib-files-as-linker-input.md).

- O arquivo DLL real.

Para usar uma DLL por vinculação implícita, um executável deve incluir os arquivos de cabeçalho que declaram os dados C++ , as funções ou as classes exportadas pela dll em cada arquivo de origem que contém chamadas para os dados, funções e classes exportados. De uma perspectiva de codificação, as chamadas para as funções exportadas são assim como qualquer outra chamada de função.

Para criar o arquivo executável de chamada, você deve vincular com a biblioteca de importação. Se você usar um makefile externo ou um sistema de compilação, especifique o nome do arquivo da biblioteca de importação no qual você listará outros arquivos de objeto (. obj) ou bibliotecas que você vincular.

O sistema operacional deve ser capaz de localizar o arquivo DLL ao carregar o executável de chamada. Isso significa que seu aplicativo deve implantar ou verificar a existência da DLL quando o aplicativo é instalado.

<a name="linking-explicitly"></a>

## <a name="how-to-link-explicitly-to-a-dll"></a>Como vincular explicitamente a uma DLL

Para usar uma DLL por vinculação explícita, os aplicativos devem fazer uma chamada de função para carregar explicitamente a DLL em tempo de execução. Para vincular explicitamente a uma DLL, um aplicativo deve:

- Chame [LoadLibrary](loadlibrary-and-afxloadlibrary.md), `LoadLibraryEx`, ou uma função semelhante para carregar a dll e obter um identificador de módulo.

- Chame o [GetProcAddress](getprocaddress.md) para obter um ponteiro de função para cada função exportada que o aplicativo chama. Como os aplicativos chamam as funções de DLL por meio de um ponteiro, o compilador não gera referências externas, portanto, não há necessidade de vincular a uma biblioteca de importação. No entanto, você deve `typedef` ter `using` uma instrução ou que define a assinatura de chamada das funções exportadas que você chama.

- Chame [FreeLibrary](freelibrary-and-afxfreelibrary.md) quando terminar com a dll.

Por exemplo, essa função de exemplo `LoadLibrary` chama para carregar uma DLL chamada "MyDLL", `GetProcAddress` chama para obter um ponteiro para uma função chamada "DLLFunc1", chama a função e salva o resultado e, em `FreeLibrary` seguida, chama para descarregar a dll.

```C
#include "windows.h"

typedef HRESULT (CALLBACK* LPFNDLLFUNC1)(DWORD,UINT*);

HRESULT LoadAndCallSomeFunction(DWORD dwParam1, UINT * puParam2)
{
    HINSTANCE hDLL;               // Handle to DLL
    LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
    HRESULT hrReturnVal;

    hDLL = LoadLibrary("MyDLL");
    if (NULL != hDLL)
    {
        lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "DLLFunc1");
        if (NULL != lpfnDllFunc1)
        {
            // call the function
            hrReturnVal = lpfnDllFunc1(dwParam1, puParam2);
        }
        else
        {
            // report the error
            hrReturnVal = ERROR_DELAY_LOAD_FAILED;
        }
        FreeLibrary(hDLL);
    }
    else
    {
        hrReturnVal = ERROR_DELAY_LOAD_FAILED;
    }
    return hrReturnVal;
}
```

Ao contrário deste exemplo, na maioria dos casos, você `LoadLibrary` deve `FreeLibrary` chamar e apenas uma vez em seu aplicativo para uma determinada dll, especialmente se você pretende chamar várias funções na DLL ou chamar dll de chamada repetidamente.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Trabalhando com bibliotecas de importação e arquivos de exportação](reference/working-with-import-libraries-and-export-files.md)

- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)

## <a name="see-also"></a>Consulte também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
