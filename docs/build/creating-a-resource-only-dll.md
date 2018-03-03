---
title: Criar uma DLL somente recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- resource-only DLLs [C++], creating
- DLLs [C++], creating
ms.assetid: e6b1d4da-7275-467f-a58c-a0a8a5835199
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dd65085c9a0ecc0479c7d22feb5587d1e94447de
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-resource-only-dll"></a>Criando uma DLL somente de recurso  
  
Uma DLL somente de recursos é uma DLL que contém apenas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo. Usar uma DLL somente de recursos é uma boa maneira de compartilhar o mesmo conjunto de recursos entre vários programas. Também é uma boa maneira de fornecer um aplicativo com os recursos localizados para vários idiomas (consulte [recursos localizados em aplicativos MFC: DLLs satélite](../build/localized-resources-in-mfc-applications-satellite-dlls.md)).  
  
Para criar uma DLL somente de recursos, você cria um novo projeto de DLL Win32 (não MFC) e adicione os recursos para o projeto.  
  
-   Selecione o projeto do Win32 no **novo projeto** caixa de diálogo caixa e especifique um tipo de projeto DLL no Assistente de projeto Win32.  
  
-   Criar um novo script de recurso que contém os recursos (como uma cadeia de caracteres ou um menu) para a DLL e salve o arquivo. rc.  
  
-   Sobre o **projeto** menu, clique em **Add Existing Item**e, em seguida, inserir o novo arquivo. rc no projeto.  
  
-   Especifique o [/NOENTRY](../build/reference/noentry-no-entry-point.md) opção de vinculador. /NOENTRY impede que o vinculador vincular uma referência para `_main` a DLL; essa opção é necessária para criar uma DLL somente de recursos.  
  
-   Compile a DLL.  
  
O aplicativo que usa a DLL somente de recursos deve chamar [LoadLibrary](../build/loadlibrary-and-afxloadlibrary.md) explicitamente vincular para a DLL. Para acessar os recursos, chame as funções genéricas `FindResource` e `LoadResource`, que funcionam em qualquer tipo de recurso, ou chame uma das seguintes funções específicas do recurso:  
  
-   `FormatMessage`  
  
-   `LoadAccelerators`  
  
-   `LoadBitmap`  
  
-   `LoadCursor`  
  
-   `LoadIcon`  
  
-   `LoadMenu`  
  
-   `LoadString`  
  
O aplicativo deve chamar `FreeLibrary` quando ele for concluído usando os recursos.  
  
## <a name="see-also"></a>Consulte também  
  
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)  
[DLLs no Visual C++](../build/dlls-in-visual-cpp.md)