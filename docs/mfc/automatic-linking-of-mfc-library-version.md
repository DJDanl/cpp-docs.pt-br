---
title: "Vinculação automática da versão da biblioteca MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: defaultlib
dev_langs: C++
helpviewer_keywords:
- defaultlib in MFC
- automatic links [MFC]
- MFC libraries, linking to
- linking [MFC], automatic of MFC library version
- linking [MFC]
- linking [MFC], of MFC
- MFC libraries, versions
ms.assetid: 02af4a20-2034-4fce-b200-c2202c3c8311
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ddc156d8518318a686796a25e89ee84a9a67ee59
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="automatic-linking-of-mfc-library-version"></a>Vinculação automática da versão da biblioteca MFC
Nas versões do MFC antes da versão 3.0 (antes do Visual C++ versão 2.0), era necessário especificar manualmente a versão correta da biblioteca MFC na lista de bibliotecas de entrada para o vinculador. Com MFC versão 3.0 e posterior, não é necessário especificar manualmente a versão da biblioteca do MFC. Em vez disso, os arquivos de cabeçalho MFC determinam automaticamente a versão correta da biblioteca do MFC, com base nos valores definidos com `#define`, como **Debug** ou **Unicode**. Adicionar os arquivos de cabeçalho MFC **/defaultlib** diretivas instrui o vinculador para vincular em uma versão específica da biblioteca do MFC.  
  
 Por exemplo, o seguinte fragmento de código do AFX. Arquivo de cabeçalho H instrui o vinculador a vincular em ambos o NAFXCWD. LIB ou NAFXCW. Versão de biblioteca do MFC, dependendo se você estiver usando a versão de depuração de MFC:  
  
```c++
#ifndef _UNICODE 
#ifdef _DEBUG
#pragma comment(lib, "nafxcwd.lib")
#else
#pragma comment(lib, "nafxcw.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment(lib, "uafxcwd.lib")
#else
#pragma comment(lib, "uafxcw.lib")
#endif
#endif
```  
  
 Arquivos de cabeçalho MFC também vincular em bibliotecas de todos os itens necessárias, incluindo bibliotecas MFC, bibliotecas de Win32, bibliotecas OLE, criadas a partir de exemplos das bibliotecas OLE, bibliotecas ODBC e assim por diante. As bibliotecas de Win32 incluem Kernel32.Lib, User32.Lib e GDI32.Lib.  
  
## <a name="see-also"></a>Consulte também  
 [Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

