---
title: 'Como: compilar código MFC e ATL usando - clr'
ms.custom: get-started-article
ms.date: 11/04/2016
helpviewer_keywords:
- MFC [C++], interoperability
- ATL [C++], interoperability
- mixed assemblies [C++], MFC code
- mixed assemblies [C++], ATL code
- /clr compiler option [C++], compiling ATL and MFC code
- interoperability [C++], /clr compiler option
- regular MFC DLLs [C++], /clr compiler option
- interop [C++], /clr compiler option
- extension DLLs [C++], /clr compiler option
ms.assetid: 12464bec-33a4-482c-880a-c078de7f6ea5
ms.openlocfilehash: e5e9f800d6316e3b4f1209ec62440ae42233fc13
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50638068"
---
# <a name="how-to-compile-mfc-and-atl-code-by-using-clr"></a>Como compilar código MFC e ATL usando /clr

Este tópico discute como compilar programas existentes do MFC e ATL para direcionar o Common Language Runtime.

### <a name="to-compile-an-mfc-executable-or-regular-mfc-dll-by-using-clr"></a>Para compilar uma DLL do MFC MFC regulares ou executável usando /clr

1. Clique com botão direito no projeto no **Gerenciador de soluções** e, em seguida, clique em **propriedades**.

1. No **propriedades do projeto** diálogo caixa, expanda o nó lado **propriedades de configuração** e selecione **geral**. No painel direito, sob **padrões de projeto**, defina **suporte do Common Language Runtime** para **suporte a Common Language Runtime (/ clr)**.

   No mesmo painel, verifique se **uso do MFC** é definido como **usar MFC em uma DLL compartilhada**.

1. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Certifique-se de que **formato de informações de depuração** é definido como **banco de dados do programa /Zi** (não **/ZI**).

1. Selecione o **geração de código** nó. Definir **habilitar recompilação mínima** à **não (/ Gm-)**. Também defina **verificações básicas de tempo de execução** à **padrão**.

1. Sob **propriedades de configuração**, selecione **C/C++** e, em seguida, **geração de código**. Certifique-se de que **biblioteca de tempo de execução** está definida como **DLL de depuração multi-threaded (/ MDd)** ou **DLL multi-threaded (/ MD)**.

1. Em Stdafx. h, adicione a seguinte linha.

    ```
    #using <System.Windows.Forms.dll>
    ```

### <a name="to-compile-an-mfc-extension-dll-by-using-clr"></a>Para compilar uma DLL de extensão do MFC usando /clr

1. Siga as etapas em "To compilar uma DLL do MFC MFC regulares ou executável usando /clr".

1. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **cabeçalhos pré-compilados**. Definir **criar/usar cabeçalho de pré-compilado** à **não usar cabeçalhos pré-compilados**.

   Como alternativa, na **Gerenciador de soluções**, clique com botão direito Stdafx e, em seguida, clique em **propriedades**. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Definir **compilar com o suporte a Common Language Runtime** à **suporte No Common Language Runtime**.

1. Para o arquivo que contém o DllMain e qualquer coisa ele chama, na **Gerenciador de soluções**, o arquivo com o botão direito e, em seguida, clique em **propriedades**. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. No painel direito, sob **padrões de projeto**, defina **compilar com o suporte a Common Language Runtime** para **suporte No Common Language Runtime**.

### <a name="to-compile-an-atl-executable-by-using-clr"></a>Para compilar um executável ATL usando /clr

1. Na **Gerenciador de soluções**, clique com botão direito no projeto e, em seguida, clique em **propriedades**.

1. No **propriedades do projeto** diálogo caixa, expanda o nó lado **propriedades de configuração** e selecione **geral**. No painel direito, sob **padrões de projeto**, defina **suporte do Common Language Runtime** para **suporte a Common Language Runtime (/ clr)**.

1. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Certifique-se de que **formato de informações de depuração** é definido como **banco de dados do programa /Zi** (não **/ZI**).

1. Selecione o **geração de código** nó. Definir **habilitar recompilação mínima** à **não (/ Gm-)**. Também defina **verificações básicas de tempo de execução** à **padrão**.

1. Sob **propriedades de configuração**, selecione **C/C++** e, em seguida, **geração de código**. Certifique-se de que **biblioteca de tempo de execução** está definida como **DLL de depuração multi-threaded (/ MDd)** ou **DLL multi-threaded (/ MD)**.

1. Para cada gerados por MIDL arquivo (arquivos C), clique no arquivo no **Gerenciador de soluções** e, em seguida, clique em **propriedades**. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Definir **compilar com o suporte a Common Language Runtime** à **suporte No Common Language Runtime**.

### <a name="to-compile-an-atl-dll-by-using-clr"></a>Para compilar uma DLL do ATL usando /clr

1. Siga as etapas na seção "para compilar uma executável de ATL usando /clr".

1. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **cabeçalhos pré-compilados**. Definir **criar/usar cabeçalho de pré-compilado** à **não usar cabeçalhos pré-compilados**.

   Como alternativa, na **Gerenciador de soluções**, clique com botão direito Stdafx e, em seguida, clique em **propriedades**. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Definir **compilar com o suporte a Common Language Runtime** à **suporte No Common Language Runtime**.

1. Para o arquivo que contém o DllMain e qualquer coisa ele chama, na **Gerenciador de soluções**, o arquivo com o botão direito e, em seguida, clique em **propriedades**. Sob **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. No painel direito, sob **padrões de projeto**, defina **compilar com o suporte a Common Language Runtime** para **suporte No Common Language Runtime**.

## <a name="see-also"></a>Consulte também

[Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)