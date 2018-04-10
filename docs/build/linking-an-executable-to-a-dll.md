---
title: Vincular um executável para uma DLL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
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
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6bdc8d4b372a589beb51d2f8a9bc05b1aa241c48
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="link-an-executable-to-a-dll"></a>Vincular um executável para uma DLL  
  
Um arquivo executável contém links para (ou carrega) uma DLL de duas maneiras:  
  
-   *Vinculação implícita*, onde o sistema operacional carrega a DLL quando o executável usá-lo é carregado. O executável do cliente chama as funções exportadas da DLL como se as funções foram estaticamente vinculadas e contidas no executável. Vinculação implícita é às vezes conhecido como *de carga estática* ou *vinculação dinâmica do tempo de carregamento*.  
  
-   *Vinculando explicitamente*, onde o sistema operacional carrega a DLL sob demanda em tempo de execução. Um executável que usa um DLL por meio da vinculação explícita deve fazer chamadas de função explicitamente carregar e descarregar a DLL e para acessar as funções exportadas pela DLL. Ao contrário das chamadas de funções em uma biblioteca estaticamente vinculada, o executável do cliente deve chamar as funções exportadas em uma DLL por meio de um ponteiro de função. Vinculando explicitamente é às vezes conhecido como *dinâmico de carga* ou *vinculação dinâmica do tempo de execução*.  
  
Um executável pode usar qualquer um dos métodos de vinculação para vincular a mesma DLL. Além disso, esses métodos não são mutuamente exclusivos; um executável implicitamente pode vincular a uma DLL e outro pode anexar a ela explicitamente.  
  
<a name="determining-which-linking-method-to-use"></a>  
  
## <a name="determine-which-linking-method-to-use"></a>Determinar qual método de associação usar  
  
Se deseja usar vinculação implícita ou explícita de vinculação é uma decisão de arquitetura que você deve fazer para seu aplicativo. Há vantagens e desvantagens de cada método.  
  
### <a name="implicit-linking"></a>Vinculação implícita  
  
Vinculação implícita ocorre quando o código de um aplicativo chama uma função DLL exportada. Quando o código-fonte para o executável de chamada é compilado ou montado, a chamada de função DLL gera uma referência de função externa no código do objeto. Para resolver essa referência externa, o aplicativo deve estabelecer um vínculo com a biblioteca de importação (arquivo. lib) fornecida pelo fabricante da DLL.  
  
A biblioteca de importação contém apenas o código para carregar a DLL e implementar chamadas para funções na DLL. Localizando uma função externa em uma biblioteca de importação informa o vinculador que o código para essa função está em uma DLL. Para resolver referências externas para DLLs, o vinculador simplesmente adiciona informações para o arquivo executável que informa o sistema onde encontrar o código DLL, quando o processo é iniciado.  
  
Quando o sistema inicia um programa que contém referências dinamicamente vinculadas, ele usa as informações no arquivo executável do programa para localizar as DLLs necessárias. Se ele não é possível localizar a DLL, o sistema encerra o processo e exibe uma caixa de diálogo que relata o erro. Caso contrário, o sistema mapeia os módulos DLL no espaço de endereço do processo.  
  
Se qualquer uma das DLLs às quais tem uma função de ponto de entrada para o código de inicialização e encerramento como `DllMain`, o sistema operacional chamará a função. Um dos parâmetros passados para a função de ponto de entrada especifica um código que indica a DLL é anexar ao processo. Se a função de ponto de entrada não retornar TRUE, o sistema encerra o processo e relata o erro.  
  
Por fim, o sistema modifica o código executável do processo para fornecer endereços iniciais para as funções DLL.  
  
Como o restante do código do programa, código DLL é mapeado no espaço de endereço do processo quando o processo é iniciado e ele é carregado na memória somente quando necessário. Como resultado, o `PRELOAD` e `LOADONCALL` atributos de código usados por arquivos. def para controle de carregamento em versões anteriores do Windows não têm significado.  
  
### <a name="explicit-linking"></a>Vinculando explicitamente  
  
A maioria dos aplicativos usar vinculação implícita porque ele é o método mais fácil de vinculação para usar. No entanto, há momentos em vinculando explicitamente é necessário. Aqui estão algumas razões comuns para usar vinculando explicitamente:  
  
-   O aplicativo não sabe o nome de uma DLL que carrega até o tempo de execução. Por exemplo, o aplicativo pode obter o nome da DLL e as funções exportadas de um arquivo de configuração na inicialização.  
  
-   Um processo que usa a vinculação implícita é encerrado pelo sistema operacional, se a DLL não foi encontrada na inicialização do processo. Um processo que usa a vinculação explícita não será encerrado nessa situação e pode tentar recuperar do erro. Por exemplo, o processo pode notificar o usuário sobre o erro e que o usuário especifique outro caminho para a DLL.  
  
-   Um processo que usa a vinculação implícita também será finalizado se qualquer uma das DLLs às quais ele está vinculado para ter uma `DllMain` função falhará. Um processo que usa a vinculação explícita não é encerrado nessa situação.  
  
-   Um aplicativo que implicitamente contém links para várias DLLs pode ser lento para ser iniciado porque o Windows carrega todos os DLLs quando o aplicativo é carregado. Para melhorar o desempenho de inicialização, um aplicativo pode vincular implicitamente apenas a essas DLLs necessárias imediatamente após o carregamento e aguarde até que outras DLLs são necessárias para vinculá-los explicitamente.  
  
-   Vinculando explicitamente elimina a necessidade de vincular o aplicativo usando uma biblioteca de importação. Se as alterações na DLL causam ordinais de exportação alterar, aplicativos que usam a vinculação explícita não é necessário vincular novamente se eles chamam `GetProcAddress` usando o nome de uma função e não é um valor ordinal, enquanto os aplicativos que usam a vinculação implícita devem vincular novamente para o nova biblioteca de importação.  
  
Aqui estão dois riscos de vinculação explícita para estar ciente de:  
  
-   Se a DLL tem uma `DllMain` função de ponto de entrada, o sistema operacional chama a função no contexto do thread que chamou `LoadLibrary`. A função de ponto de entrada não é chamada se a DLL já está anexada ao processo devido a uma chamada anterior a `LoadLibrary` que não teve nenhuma chamada correspondente para o `FreeLibrary` função. Vinculando explicitamente pode causar problemas se a DLL usa um `DllMain` função para executar a inicialização para cada thread de um processo porque já existem threads quando `LoadLibrary` (ou `AfxLoadLibrary`) é chamado não foram inicializados.  
  
-   Se uma DLL declarar dados estáticos extensão como `__declspec(thread)`, isso poderá causar uma falha de proteção se explicitamente vinculado. Depois que a DLL é carregada por uma chamada para `LoadLibrary`, ele faz com que uma falha de proteção sempre que o código faz referência a esses dados. (Os dados de extensão static incluem itens estáticos globais e locais.) Portanto, quando você criar uma DLL, você deve evitar o uso de armazenamento local de thread ou informar os usuários DLL sobre as possíveis armadilhas de dinamicamente ao carregar a DLL. Para obter mais informações, consulte [usando o armazenamento local de thread em uma biblioteca de vínculo dinâmico (SDK do Windows)](http://msdn.microsoft.com/library/windows/desktop/ms686997).  
  
<a name="linking-implicitly"></a>  
  
## <a name="how-to-link-implicitly-to-a-dll"></a>Como vincular implicitamente para uma DLL  
  
Para usar uma DLL por meio da vinculação implícita, executáveis de cliente devem obter esses arquivos do provedor da DLL:  
  
-   Um ou mais arquivos de cabeçalho (arquivos. h) que contêm as declarações dos dados exportados, funções e/ou as classes C++ na DLL. Classes, funções e os dados exportados pela DLL devem ser marcados `__declspec(dllimport)` no arquivo de cabeçalho. Para obter mais informações, consulte [dllexport, dllimport](../cpp/dllexport-dllimport.md).  
  
-   Uma biblioteca de importação para vincular em seu executável. O vinculador cria a biblioteca de importação quando a DLL é compilada. Para obter mais informações, consulte [. Arquivos LIB](../build/reference/dot-lib-files-as-linker-input.md).  
  
-   O arquivo DLL real.  
  
Para usar uma DLL por meio da vinculação implícita, um executável deve incluir os arquivos de cabeçalho que declara os dados, funções ou classes C++ exportadas pela DLL em cada arquivo de origem que contém as chamadas para os dados exportados, funções e classes. De uma perspectiva de codificação, chamadas para as funções exportadas são exatamente como qualquer outra chamada de função.  
  
Para criar o arquivo executável de chamada, você deve estabelecer um vínculo com a biblioteca de importação. Se você usar um makefile externo ou sistema de compilação, especifique o nome do arquivo de biblioteca de importação onde você lista outros arquivos de objeto (. obj) ou bibliotecas que você vincular.  
  
O sistema operacional deve ser capaz de localizar o arquivo DLL quando ele carrega o executável de chamada. Isso significa que seu aplicativo deve implantar ou verificar a existência da DLL quando seu aplicativo está instalado.   
  
<a name="linking-explicitly"></a>  
  
## <a name="how-to-link-explicitly-to-a-dll"></a>Como vincular explicitamente para uma DLL  
  
Para usar uma DLL por meio da vinculação explícita, aplicativos devem fazer uma função chamar explicitamente carregar o DLL em tempo de execução. Para vincular explicitamente para uma DLL, um aplicativo deve:  
  
-   Chamar [LoadLibrary](loadlibrary-and-afxloadlibrary.md), `LoadLibraryEx`, ou uma função semelhante ao carregar a DLL e obter um identificador de módulo.  
  
-   Chamar [GetProcAddress](getprocaddress.md) obter um ponteiro de função para cada função que o aplicativo chama exportada. Como aplicativos chamam as funções DLL por meio de um ponteiro, o compilador não gera referências externas, portanto não é necessário vincular a uma biblioteca de importação. No entanto, você deve ter uma `typedef` ou `using` que define a assinatura de chamada das funções exportadas que você chamar a instrução.   
  
-   Chamar [FreeLibrary](freelibrary-and-afxfreelibrary.md) quando concluir a DLL.  
  
Por exemplo, essa função de exemplo chama `LoadLibrary` para carregar uma DLL denominada "MyDLL", chamadas de `GetProcAddress` para obter um ponteiro para uma função chamada "DLLFunc1", chama a função e salva o resultado e, em seguida, chama `FreeLibrary` descarregar a DLL. 
  
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
  
Ao contrário de neste exemplo, na maioria dos casos você deve chamar `LoadLibrary` e `FreeLibrary` apenas uma vez em seu aplicativo para uma determinada DLL, especialmente se você pretende chamar várias funções na DLL ou chamar DLL funções repetidamente.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Trabalhando com bibliotecas de importação e arquivos de exportação](../build/reference/working-with-import-libraries-and-export-files.md)  
  
-   [O caminho de pesquisa usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)