---
title: "Versões AFXDLL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: afxdll
dev_langs: C++
helpviewer_keywords:
- MFC DLLs [MFC], dynamic linking to library
- AFXDLL library
- application wizards [MFC], default uses AFXDLL
- MFC libraries [MFC], dynamic linking
- MFC, AFXDLL version
- DLL version of MFC [MFC]
ms.assetid: c078ae8f-85a9-43cb-9ded-c09ca2c45723
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bd1db02541927b9ccb3827ee1fdd9e35543a7d6d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="afxdll-versions"></a>Versões AFXDLL
Em vez de criar seu aplicativo por meio da vinculação estaticamente para as bibliotecas de código de objeto do MFC, você pode criar seu aplicativo para usar uma das bibliotecas AFXDLL, que contêm MFC em uma DLL que podem ser compartilhados por vários aplicativos em execução. Para uma tabela de nomes AFXDLL, consulte [DLLs: convenções de nomenclatura](../build/naming-conventions-for-mfc-dlls.md).  
  
> [!NOTE]
>  Por padrão, o Assistente de aplicativo MFC cria um projeto AFXDLL. Para usar a vinculação estática do código MFC em vez disso, defina o **usar MFC em uma biblioteca estática** opção no Assistente de aplicativo MFC. Vinculação estática não está disponível na Standard Edition do Visual C++.  
  
## <a name="see-also"></a>Consulte também  
 [Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

