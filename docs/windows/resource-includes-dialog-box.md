---
title: "Caixa de diálogo inclui o recurso | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.editors.resourceincludes
dev_langs: C++
helpviewer_keywords:
- Resource Includes dialog box
- rc files, changing storage
- symbol header files, changing
- compiling source code, including resources
- .rc files, changing storage
- symbol header files, read-only
- symbols, symbol header files
ms.assetid: 659a54e6-e416-4045-8411-798730ff4ce3
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 610e970ad84c6c89d91182b7a61bb759112fcd7d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-includes-dialog-box"></a>Caixa de diálogo Recurso Inclui
Você pode usar o **inclui recursos** caixa de diálogo para modificar a organização de trabalho normal do ambiente de armazenamento de todos os recursos no arquivo. RC do projeto e todos os [símbolos](../windows/symbols-resource-identifiers.md) em Resource.h.  
  
 Para abrir o **inclui recursos** caixa de diálogo, clique uma RC do arquivo em [exibição recursos](../windows/resource-view-window.md), em seguida, escolha **inclui recursos** no menu de atalho.  
  
 **Arquivo de cabeçalho de símbolo**  
 Permite que você altere o nome do arquivo de cabeçalho onde as definições de símbolo para o arquivo de recurso são armazenadas. Para obter mais informações, consulte [alterar nomes de arquivos de cabeçalho de símbolo](../windows/changing-the-names-of-symbol-header-files.md).  
  
 **Diretivas de símbolo somente leitura**  
 Permite que você inclua os arquivos de cabeçalho que contém os símbolos que não devem ser modificados durante uma sessão de edição. Por exemplo, você pode incluir um arquivo de símbolo que é compartilhado entre vários projetos. Você também pode incluir arquivos do MFC. h. Para obter mais informações, consulte [incluindo compartilhados (somente leitura) ou símbolos calculados](../windows/including-shared-read-only-or-calculated-symbols.md).  
  
 **Diretivas de tempo de compilação**  
 Permite que você inclua os arquivos de recursos que são criados e editados separadamente dos recursos em seu arquivo de recurso principal contém diretivas de tempo de compilação (como aquelas que incluem condicionalmente recursos) ou contêm recursos em um formato personalizado. Você também pode usar a caixa de diretivas de tempo de compilação para incluir arquivos de recursos padrão do MFC. Para obter mais informações, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).  
  
> [!NOTE]
>  Entradas nessas caixas de texto aparecem no arquivo. rc marcado por `TEXTINCLUDE 1`, `TEXTINCLUDE 2`, e `TEXTINCLUDE 3` respectivamente. Para obter mais informações, consulte [TN035: usando vários arquivos de recurso e arquivos de cabeçalho com o Visual C++](../mfc/tn035-using-multiple-resource-files-and-header-files-with-visual-cpp.md).  
  
 Depois de fazer alterações em seu arquivo de recursos usando o **inclui recursos** caixa de diálogo, você precisa fechar o arquivo. RC e reabri-lo para que as alterações entrem em vigor. Para obter mais informações, consulte [incluindo recursos em tempo de compilação](../windows/how-to-include-resources-at-compile-time.md).  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Como: especificar diretórios de inclusão para recursos](../windows/how-to-specify-include-directories-for-resources.md)   
 [Símbolos: Identificadores de recursos](../windows/symbols-resource-identifiers.md)   
 [Arquivos de recurso](../windows/resource-files-visual-studio.md)   
 [Editores de recursos](../windows/resource-editors.md)