---
title: "Convenções de nomenclatura de biblioteca | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- NAFXCW.LIB [MFC]
- libraries [MFC], static
- coding conventions [MFC], MFC library names
- NAFXCWD.LIB [MFC]
- console applications [MFC], MFC library versions
- naming conventions [MFC], MFC object code libraries
- object code libraries, MFC naming conventions
- object code libraries
- conventions [MFC], MFC library names
- MFC libraries, naming conventions
ms.assetid: 39fe7d93-5a14-4c6a-b16c-bf318fa01278
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 14e217b3cfd9f3618046cf1a0ca825eb2e6492f2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="library-naming-conventions"></a>Convenções de nomenclatura da biblioteca
Bibliotecas de código de objeto para MFC usam as seguintes convenções de nomenclatura. Os nomes de biblioteca que o formulário  
  
 *u*AFX*c*W*d*. LIB  
  
 onde as letras mostradas em itálico minúsculas são espaços reservados para especificadores cujos significados são mostrados na tabela a seguir:  
  
### <a name="library-naming-conventions"></a>Convenções de nomenclatura da biblioteca  
  
|Especificador|Valores e significados|  
|---------------|-------------------------|  
|*u*|ANSI (N) ou Unicode (U)|  
|*c*|Tipo de programa para criar: C = all|  
|*d*|Depurar ou versão: D = Debug; omitir um especificador de versão|  
  
 O padrão é criar uma aplicativo de ANSI do Windows para a plataforma Intel de depuração: Nafxcwd. Todas as bibliotecas listadas na tabela a seguir estão incluídas pré-compiladas no diretório \atlmfc\lib.  
  
### <a name="static-link-library-naming-conventions"></a>Biblioteca de vínculo estático convenções de nomenclatura  
  
|Biblioteca|Descrição|  
|-------------|-----------------|  
|NAFXCW.LIB|Biblioteca de vínculo estático do MFC, versão de lançamento|  
|NAFXCWD.LIB|Biblioteca de vínculo estático do MFC, versão de depuração|  
|UAFXCW. LIB|Biblioteca de vínculo estático do MFC com suporte a Unicode, versão de lançamento|  
|UAFXCWD. LIB|Biblioteca de vínculo estático do MFC com suporte a Unicode, versão de depuração|  
  
> [!NOTE]
>  Se você precisar criar uma versão de biblioteca, consulte o arquivo Leiame. txt no diretório \atlmfc\src\mfc. Esse arquivo descreve como usar o makefile fornecido com NMAKE.  
  
 Para obter mais informações, consulte [convenções de nomenclatura para DLLs MFC](../build/naming-conventions-for-mfc-dlls.md) e [Unicode versões das bibliotecas MFC](../mfc/unicode-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

