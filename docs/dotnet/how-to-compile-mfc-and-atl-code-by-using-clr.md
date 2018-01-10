---
title: "Como: compilar MFC e ATL código usando o clr-| Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
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
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: f03e324cf4f88d47232cba5e15ec65181af91feb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-compile-mfc-and-atl-code-by-using-clr"></a>Como compilar código MFC e ATL usando /clr
Este tópico discute como compilar os programas existentes MFC e ATL para direcionar o Common Language Runtime.  
  
### <a name="to-compile-an-mfc-executable-or-regular-mfc-dll-by-using-clr"></a>Para compilar uma DLL do MFC MFC regular ou executável usando /clr  
  
1.  Clique com botão direito no projeto no **Solution Explorer** e, em seguida, clique em **propriedades**.  
  
2.  No **propriedades do projeto** caixa de diálogo caixa, expanda o nó lado **propriedades de configuração** e selecione **geral**. No painel direito, em **padrões do projeto**, defina **suporte a Common Language Runtime** para **tempo de execução de linguagem comum suporte (/ clr)**.  
  
     No painel do mesmo, verifique se **uso de MFC** é definido como **Use MFC em uma DLL compartilhada**.  
  
3.  Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Verifique se **formato informações de depuração** é definido como **banco de dados do programa /Zi** (não **/ZI**).  
  
4.  Selecione o **geração de código** nó. Definir **habilitar recompilação mínima** para **não (/ Gm-)**. Também definir **verificações de tempo de execução básico** para **padrão**.  
  
5.  Em **propriedades de configuração**, selecione **C/C++** e **geração de código**. Verifique se **biblioteca de tempo de execução** está definida como **multi-threaded depurar DLL (/ MDd)** ou **multi-threaded DLL (/ MD)**.  
  
6.  Em Stdafx. h, adicione a linha a seguir.  
  
    ```  
    #using <System.Windows.Forms.dll>  
    ```  
  
### <a name="to-compile-an-mfc-extension-dll-by-using-clr"></a>Para compilar uma DLL de extensão do MFC usando /clr  
  
1.  Siga as etapas em "To compilar uma DLL do MFC MFC regular ou executável, usando /clr".  
  
2.  Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **cabeçalhos pré-compilados**. Definir **criar/usar cabeçalho de pré-compilado** para **não usar cabeçalhos pré-compilados**.  
  
     Como alternativa, em **Solution Explorer**, clique com botão direito Stdafx.cpp e, em seguida, clique em **propriedades**. Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Definir **compilar com suporte a Common Language Runtime** para **suporte No Common Language Runtime**.  
  
3.  Para o arquivo que contém DllMain e qualquer coisa chama, em **Solution Explorer**, clique no arquivo e, em seguida, clique em **propriedades**. Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. No painel direito, em **padrões do projeto**, defina **compilar com suporte a Common Language Runtime** para **suporte No Common Language Runtime**.  
  
### <a name="to-compile-an-atl-executable-by-using-clr"></a>Para compilar um executável ATL usando /clr  
  
1.  Em **Solution Explorer**, clique com o botão direito e, em seguida, clique em **propriedades**.  
  
2.  No **propriedades do projeto** caixa de diálogo caixa, expanda o nó lado **propriedades de configuração** e selecione **geral**. No painel direito, em **padrões do projeto**, defina **suporte a Common Language Runtime** para **tempo de execução de linguagem comum suporte (/ clr)**.  
  
3.  Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Verifique se **formato informações de depuração** é definido como **banco de dados do programa /Zi** (não **/ZI**).  
  
4.  Selecione o **geração de código** nó. Definir **habilitar recompilação mínima** para **não (/ Gm-)**. Também definir **verificações de tempo de execução básico** para **padrão**.  
  
5.  Em **propriedades de configuração**, selecione **C/C++** e **geração de código**. Verifique se **biblioteca de tempo de execução** está definida como **multi-threaded depurar DLL (/ MDd)** ou **multi-threaded DLL (/ MD)**.  
  
6.  Para cada gerados por MIDL arquivo (C arquivos), clique no arquivo em **Solution Explorer** e, em seguida, clique em **propriedades**. Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Definir **compilar com suporte a Common Language Runtime** para **suporte No Common Language Runtime**.  
  
### <a name="to-compile-an-atl-dll-by-using-clr"></a>Para compilar uma DLL da ATL usando /clr  
  
1.  Siga as etapas na seção "para compilar um executável de ATL usando /clr".  
  
2.  Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **cabeçalhos pré-compilados**. Definir **criar/usar cabeçalho de pré-compilado** para **não usar cabeçalhos pré-compilados**.  
  
     Como alternativa, em **Solution Explorer**, clique com botão direito Stdafx.cpp e, em seguida, clique em **propriedades**. Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. Definir **compilar com suporte a Common Language Runtime** para **suporte No Common Language Runtime**.  
  
3.  Para o arquivo que contém DllMain e qualquer coisa chama, em **Solution Explorer**, clique no arquivo e, em seguida, clique em **propriedades**. Em **propriedades de configuração**, expanda o nó do lado **C/C++** e selecione **geral**. No painel direito, em **padrões do projeto**, defina **compilar com suporte a Common Language Runtime** para **suporte No Common Language Runtime**.  
  
## <a name="see-also"></a>Consulte também  
 [Assemblies mistos (nativos e gerenciados)](../dotnet/mixed-native-and-managed-assemblies.md)