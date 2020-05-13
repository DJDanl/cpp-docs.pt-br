---
title: Vincular um executável a uma DLL
ms.date: 08/22/2019
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
ms.openlocfilehash: 2f907fedcaaf9897749ee0eb6a7ea5a33e1af679
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417358"
---
# <a name="link-an-executable-to-a-dll"></a>Vincular um executável a uma DLL

Um arquivo executável vincula (ou carrega) uma DLL de uma das duas maneiras:

- *Vinculação implícita*, em que o sistema operacional carrega a dll ao mesmo tempo que o executável que a utiliza. O executável do cliente chama as funções exportadas da DLL da mesma forma como se as funções estivessem vinculadas estaticamente e estão contidas no executável. A vinculação implícita às vezes é chamada de *carga estática* ou *vinculação dinâmica de tempo de carregamento*.

- *Vinculação explícita*, em que o sistema operacional carrega a dll sob demanda no tempo de execução. Um executável que usa uma DLL por vinculação explícita deve carregar e descarregar a DLL explicitamente. Ele também deve configurar um ponteiro de função para acessar cada função que ele usa da DLL. Ao contrário de chamadas para funções em uma biblioteca vinculada estaticamente ou uma DLL vinculada implicitamente, o executável do cliente deve chamar as funções exportadas em uma DLL vinculada explicitamente por meio de ponteiros de função. A vinculação explícita é, às vezes, chamada de *carregamento* dinâmico ou *vinculação dinâmica em tempo de execução*.

Um executável pode usar o método de vinculação para vincular ao mesmo DLL. Além disso, esses métodos não são mutuamente exclusivos; um executável pode vincular implicitamente a uma DLL e outro pode se anexar explicitamente a ela.

<a name="determining-which-linking-method-to-use"></a>

## <a name="determine-which-linking-method-to-use"></a>Determinar qual método de vinculação usar

A possibilidade de usar vinculação implícita ou vinculação explícita é uma decisão arquitetônica que você deve fazer para seu aplicativo. Há vantagens e desvantagens em cada método.

### <a name="implicit-linking"></a>Vinculação implícita

A vinculação implícita ocorre quando o código de um aplicativo chama uma função DLL exportada. Quando o código-fonte para o executável de chamada é compilado ou montado, a chamada de função de DLL gera uma referência de função externa no código do objeto. Para resolver essa referência externa, o aplicativo deve vincular com a biblioteca de importação (arquivo. lib) fornecida pelo criador da DLL.

A biblioteca de importação contém apenas o código para carregar a DLL e implementar chamadas para funções na DLL. A localização de uma função externa em uma biblioteca de importação informa ao vinculador que o código para essa função está em uma DLL. Para resolver referências externas a DLLs, o vinculador simplesmente adiciona informações ao arquivo executável que informa ao sistema onde encontrar o código DLL quando o processo é iniciado.

Quando o sistema inicia um programa que contém referências vinculadas dinamicamente, ele usa as informações no arquivo executável do programa para localizar as DLLs necessárias. Se não for possível localizar a DLL, o sistema encerrará o processo e exibirá uma caixa de diálogo que relata o erro. Caso contrário, o sistema mapeia os módulos de DLL para o espaço de endereço do processo.

Se qualquer uma das DLLs tiver uma função de ponto de entrada para o código de inicialização e `DllMain`término, como, o sistema operacional chamará a função. Um dos parâmetros passados para a função de ponto de entrada especifica um código que indica que a DLL está anexando ao processo. Se a função de ponto de entrada não retornar TRUE, o sistema encerrará o processo e relatará o erro.

Por fim, o sistema modifica o código executável do processo para fornecer endereços iniciais para as funções de DLL.

Como o restante do código de um programa, o carregador mapeia o código da DLL para o espaço de endereço do processo quando o processo é iniciado. O sistema operacional carrega-o na memória somente quando necessário. Como resultado, os `PRELOAD` atributos de `LOADONCALL` código e usados por arquivos. def para controlar o carregamento em versões anteriores do Windows não têm mais significado.

### <a name="explicit-linking"></a>Vinculação explícita

A maioria dos aplicativos usa vinculação implícita porque é o método de vinculação mais fácil de usar. No entanto, há ocasiões em que a vinculação explícita é necessária. Aqui estão alguns motivos comuns para usar a vinculação explícita:

- O aplicativo não sabe o nome de uma DLL que ele carrega até o tempo de execução. Por exemplo, o aplicativo pode obter o nome da DLL e as funções exportadas de um arquivo de configuração na inicialização.

- Um processo que usa vinculação implícita é encerrado pelo sistema operacional se a DLL não for encontrada na inicialização do processo. Um processo que usa vinculação explícita não é encerrado nessa situação e pode tentar se recuperar do erro. Por exemplo, o processo poderia notificar o usuário sobre o erro e fazer com que o usuário especifique outro caminho para a DLL.

- Um processo que usa vinculação implícita também será encerrado se qualquer uma das DLLs vinculadas tiver uma `DllMain` função que falhe. Um processo que usa vinculação explícita não é encerrado nessa situação.

- Um aplicativo que implicitamente vincula a várias DLLs pode ser lento para iniciar porque o Windows carrega todas as DLLs quando o aplicativo é carregado. Para melhorar o desempenho de inicialização, um aplicativo pode usar apenas a vinculação implícita para DLLs necessárias imediatamente após o carregamento. Ele pode usar vinculação explícita para carregar outras DLLs somente quando elas forem necessárias.

- A vinculação explícita elimina a necessidade de vincular o aplicativo usando uma biblioteca de importação. Se as alterações na DLL fizerem a alteração dos ordinais de exportação, os aplicativos não precisarão ser revinculados se chamarem `GetProcAddress` usando o nome de uma função e não um valor ordinal. Os aplicativos que usam vinculação implícita ainda devem ser revinculados à biblioteca de importação alterada.

Aqui estão dois perigos de vinculação explícita a serem cientes de:

- Se a DLL tiver uma `DllMain` função de ponto de entrada, o sistema operacional chamará a função no contexto do thread que `LoadLibrary`chamou. A função de ponto de entrada não será chamada se a DLL já estiver anexada ao processo devido a uma chamada `LoadLibrary` anterior a que não tinha nenhuma chamada correspondente `FreeLibrary` à função. A vinculação explícita pode causar problemas se a DLL usa `DllMain` uma função para inicializar cada thread de um processo, porque qualquer thread que já existe `LoadLibrary` quando ( `AfxLoadLibrary`ou) é chamado não é inicializado.

- Se uma DLL declarar dados de extensão estática como `__declspec(thread)`, ela poderá causar uma falha de proteção se vinculada explicitamente. Depois que a DLL for carregada por uma chamada `LoadLibrary`para, ela causará uma falha de proteção sempre que o código fizer referência a esses dados. (Os dados de extensão estática incluem itens estáticos globais e locais.) É por isso que, ao criar uma DLL, você deve evitar o uso do armazenamento local de thread. Se você não puder, informe os usuários de DLL sobre as possíveis armadilhas de carregar dinamicamente sua DLL. Para obter mais informações, consulte [usando o armazenamento local de thread em uma biblioteca de vínculo dinâmico (SDK do Windows)](/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

<a name="linking-implicitly"></a>

## <a name="how-to-use-implicit-linking"></a>Como usar a vinculação implícita

Para usar uma DLL por vinculação implícita, os executáveis do cliente devem obter esses arquivos do provedor da DLL:

- Um ou mais arquivos de cabeçalho (arquivos. h) que contêm as declarações dos dados exportados, funções e classes C++ na DLL. As classes, as funções e os dados exportados pela DLL devem ser `__declspec(dllimport)` marcados no arquivo de cabeçalho. Para saber mais, confira [dllexport, dllimport](../cpp/dllexport-dllimport.md).

- Uma biblioteca de importação para vincular ao seu executável. O vinculador cria a biblioteca de importação quando a DLL é criada. Para obter mais informações, consulte [arquivos lib como entrada do vinculador](reference/dot-lib-files-as-linker-input.md).

- O arquivo DLL real.

Para usar os dados, as funções e as classes em uma DLL por vinculação implícita, qualquer arquivo de origem do cliente deve incluir os arquivos de cabeçalho que os declaram. De uma perspectiva de codificação, as chamadas para as funções exportadas são assim como qualquer outra chamada de função.

Para criar o arquivo executável do cliente, você deve vincular com a biblioteca de importação da DLL. Se você usar um makefile externo ou um sistema de compilação, especifique a biblioteca de importação junto com os outros arquivos de objeto ou bibliotecas que você vincular.

O sistema operacional deve ser capaz de localizar o arquivo DLL ao carregar o executável de chamada. Isso significa que você deve implantar ou verificar a existência da DLL ao instalar o aplicativo.

<a name="linking-explicitly"></a>

## <a name="how-to-link-explicitly-to-a-dll"></a>Como vincular explicitamente a uma DLL

Para usar uma DLL por vinculação explícita, os aplicativos devem fazer uma chamada de função para carregar explicitamente a DLL em tempo de execução. Para vincular explicitamente a uma DLL, um aplicativo deve:

- Chame [LoadLibraryEx](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryexw) ou uma função semelhante para carregar a dll e obter um identificador de módulo.

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

Ao contrário desse exemplo, na maioria dos casos, `LoadLibrary` você `FreeLibrary` deve chamar e apenas uma vez em seu aplicativo para uma determinada dll. Isso é especialmente verdadeiro se você pretende chamar várias funções na DLL ou chamar as funções de DLL repetidamente.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Trabalhando com bibliotecas de importação e arquivos de exportação](reference/working-with-import-libraries-and-export-files.md)

- [Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)

## <a name="see-also"></a>Confira também

[Criar DLLs C /C++ no Visual Studio](dlls-in-visual-cpp.md)
