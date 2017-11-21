---
title: "Convenções de nomenclatura para DLLs MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MFC libraries [C++], naming conventions
- naming conventions [C++], MFC DLLs
- MFC DLLs [C++], naming conventions
- libraries [C++], MFC DLL names
- shared DLL versions [C++]
- DLLs [C++], naming conventions
- DLLs [C++], library names
ms.assetid: 0db9c3f3-87d3-40e8-8964-250f9d2a2209
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 7b78d01405ca74acfa74f898b88d1c9b79625e99
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="naming-conventions-for-mfc-dlls"></a>Convenções de nomenclatura para DLLs MFC
As DLLs e bibliotecas incluídas no MFC seguem uma convenção de nomenclatura estruturada. Isso torna mais fácil saber qual DLL ou biblioteca você deve usar para qual finalidade.  
  
 As bibliotecas de importação necessárias para criar aplicativos ou DLLs de extensão do MFC que usam essas DLLs têm o mesmo nome de base como a DLL, mas têm uma extensão de nome de arquivo. lib.  
  
### <a name="shared-dll-naming-convention"></a>Convenção de nomenclatura de DLL compartilhada  
  
|DLL|Descrição|  
|---------|-----------------|  
|MFCx0.DLL|DLL do MFC, versão ANSI|  
|MFCx0U.DLL|DLL do MFC, versão de Unicode|  
|MFCx0D.DLL|DLL do MFC, versão ANSI de depuração|  
|MFCx0UD.DLL|DLL do MFC, versão de depuração de Unicode|  
  
 Se você está vinculando dinamicamente para a versão DLL compartilhada do MFC, se ele é de um aplicativo ou de uma DLL de extensão do MFC, você deve incluir MFCx0.DLL com seu produto. Se você precisar de suporte a Unicode em seu aplicativo, inclua MFCx0U.DLL em vez disso.  
  
 Se você está vinculando estaticamente sua DLL MFC, você deve vinculá-lo com uma das bibliotecas MFC estáticas. Essas versões são nomeadas de acordo com a convenção de [N &#124; U] AFXCW [D]. LIB. Para obter mais informações, consulte a tabela "Convenções de nomenclatura de biblioteca de vínculo estático" em [convenções de nomenclatura da biblioteca](../mfc/library-naming-conventions.md) (MFC).  
  
 Para obter uma lista das DLLs do Visual C++ que podem ser distribuídos com seus aplicativos, consulte Redist na instalação do Visual Studio.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [A convenção de nomenclatura para bibliotecas](../mfc/library-naming-conventions.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)