---
title: "-ENTRADA (símbolo de ponto de entrada) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /entry
- VC.Project.VCLinkerTool.EntryPointSymbol
dev_langs: C++
helpviewer_keywords:
- starting address
- -ENTRY linker option
- /ENTRY linker option
- ENTRY linker option
ms.assetid: 26c62ba2-4f52-4882-a7bd-7046a0abf445
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 6daafeba4376cdab679d7e93dce0605fae97a98e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="entry-entry-point-symbol"></a>/ENTRY (símbolo do ponto de entrada)
```  
/ENTRY:function  
```  
  
## <a name="remarks"></a>Comentários  
 em que:  
  
 *function*  
 Endereço de uma função que especifica um valor inicial definido pelo usuário para um arquivo .exe ou DLL.  
  
## <a name="remarks"></a>Comentários  
 A opção /ENTRY Especifica uma função de ponto de entrada como o endereço inicial para um arquivo .exe ou DLL.  
  
 A função deve ser definida para usar o `__stdcall` convenção de chamada. O valor de retorno e parâmetros dependem se o programa é um aplicativo de console, um aplicativo do windows ou uma DLL. É recomendável que você permita que o vinculador defina o ponto de entrada para que a biblioteca de tempo de execução C foi inicializada corretamente e construtores de C++ para objetos estáticos são executadas.  
  
 Por padrão, o endereço inicial é um nome de função da biblioteca de tempo de execução do C. O vinculador seleciona acordo com os atributos do programa, como mostrado na tabela a seguir.  
  
|Nome da função|Padrão para|  
|-------------------|-----------------|  
|**mainCRTStartup** (ou **wmainCRTStartup**)|Um aplicativo que usa /SUBSYSTEM; chamadas `main` (ou `wmain`)|  
|**WinMainCRTStartup** (ou **wWinMainCRTStartup**)|Um aplicativo que usa /SUBSYSTEM:**WINDOWS**; chamadas `WinMain` (ou `wWinMain`), que deve ser definido para usar`__stdcall`|  
|**Dllmaincrtstartup**|UMA DLL; chamadas `DllMain` se ele existir, que deve ser definido para usar`__stdcall`|  
  
 Se o [/DLL](../../build/reference/dll-build-a-dll.md) ou [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção não for especificada, o vinculador seleciona um ponto de entrada e o subsistema dependendo se `main` ou `WinMain` está definido.  
  
 As funções `main`, `WinMain`, e `DllMain` são as três formas do ponto de entrada definido pelo usuário.  
  
 Ao criar uma imagem gerenciada, a função especificada para /ENTRY deve ter uma assinatura de (LPVOID *var1*, DWORD *var2*, LPVOID *var3*).  
  
 Para obter informações sobre como definir seus próprios `DllMain` ponto de entrada, consulte [DLLs e Visual C++ comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md) .  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **avançado** página de propriedades.  
  
4.  Modificar o **ponto de entrada** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.EntryPointSymbol%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)