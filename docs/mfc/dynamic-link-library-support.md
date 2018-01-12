---
title: "Suporte à biblioteca de vínculo dinâmico | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- regular MFC DLLs [MFC], project targets as DLLs
- DLLs [MFC], MFC
- NAFXDW.LIB
- MFC DLLs [MFC], regular MFC DLLs
- USRDLLs, DLL support
- NAFXDWD.LIB
ms.assetid: cc31c69f-3c78-4db1-9ecd-0fd8dc3217e3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 394c48644c3b5cdc2514fefef2f4451e4098856f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="dynamic-link-library-support"></a>Suporte à biblioteca de vínculo dinâmico
As bibliotecas NAFXCW.lib e Nafxcwd (listados na tabela de convenções de nomenclatura de biblioteca de vínculo estático no [convenções de nomenclatura da biblioteca](../mfc/library-naming-conventions.md)) criar seu projeto como uma biblioteca de vínculo dinâmico, chamada de um "DLL do MFC regular" (anteriormente conhecida como uma "USRDLL") que pode ser usado com aplicativos não são criados com a biblioteca de classes. Esse suporte DLL não é o mesmo que MFCx0.DLL e MFCx0D.DLL (conhecido como AFXDLL), que contém a biblioteca de classes completa em uma DLL. Para obter mais informações, consulte [DLLs](../build/dlls-in-visual-cpp.md). Para uma tabela de nomes de DLL, consulte [convenções de nomenclatura para DLLs MFC](../build/naming-conventions-for-mfc-dlls.md).  
  
## <a name="see-also"></a>Consulte também  
 [Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

