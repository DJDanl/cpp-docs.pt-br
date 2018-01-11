---
title: Requisitos de build para controles comuns do Windows Vista | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- common controls (MFC), build requirements
- common controls (MFC)
ms.assetid: 025f7d55-55a2-4dcd-8f62-02424e3dcc04
caps.latest.revision: "18"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 76919bcdd416ed7195e94ed1fa0b2e3f3a4d573d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="build-requirements-for-windows-vista-common-controls"></a>Requisitos de build para controles comuns do Windows Vista
A biblioteca Microsoft Foundation Class (MFC) dá suporte à versão de controles comuns do Windows 6.1. Os controles comuns são incluídos no [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)] e a biblioteca está incluída no [!INCLUDE[vsipsdk](../mfc/includes/vsipsdk_md.md)]. A biblioteca fornece novos métodos que aprimoram as classes existentes e novas classes e métodos que oferecem suporte a [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)] controles comuns. Quando você criar seu aplicativo, você deve seguir os requisitos de compilação e a migração são descritos nas seções a seguir.  
  
## <a name="compilation-requirements"></a>Requisitos de compilação  
  
### <a name="supported-versions"></a>Versões com suporte  
 Algumas novas classes e métodos suportam somente [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)] e versões posteriores, enquanto outros métodos também oferecem suporte a sistemas operacionais anteriores. Uma observação a `Requirements` seção de cada tópico de método Especifica quando o requisito mínimo de sistema operacional é [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)].  
  
 Mesmo se o computador não for executado [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)], você pode criar um aplicativo MFC que será executado em [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)] se você tiver os arquivos de cabeçalho do MFC versão 6.1 em seu computador. No entanto, controles comuns que são projetados especificamente para [!INCLUDE[windowsver](../build/reference/includes/windowsver_md.md)] funcionam somente no sistema e são ignoradas pelos sistemas operacionais anteriores.  
  
### <a name="supported-character-sets"></a>Conjuntos de caracteres com suporte  
 Os novos controles comuns do Windows oferecem suporte a apenas o conjunto de caracteres Unicode e não o conjunto de caracteres ANSI. Se você criar seu aplicativo na linha de comando, use os dois seguintes definem (/ D) conjunto de caracteres de opções do compilador para especificar Unicode como subjacente:  
  
```  
/D_UNICODE /DUNICODE  
```  
  
 Se você criar seu aplicativo no ambiente de desenvolvimento integrado (IDE) do Visual Studio, especifique o **do conjunto de caracteres Unicode** opção do **do conjunto de caracteres** propriedade o **geral**  nó das propriedades do projeto.  
  
 A versão ANSI dos vários métodos MFC foram preteridos a partir controles comuns do Windows versão 6.1. Para obter mais informações, consulte [preteridos ANSI APIs](../mfc/deprecated-ansi-apis.md).  
  
## <a name="migration-requirements"></a>Requisitos de migração  
 Se você usar o IDE do Visual Studio para criar um novo aplicativo do MFC que usa controles comuns do Windows versão 6.1, o IDE declara automaticamente um manifesto apropriado. No entanto, se você migrar um aplicativo MFC existente de uma versão anterior do Visual Studio e você deseja usar os novos controles comuns, o IDE não automaticamente fornece informações do manifesto para atualizar seu aplicativo. Em vez disso, você deve inserir manualmente o seguinte código-fonte em seu arquivo Stdafx. h:  
  
```  
#ifdef UNICODE  
#if defined _M_IX86  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#elif defined _M_IA64  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#elif defined _M_X64  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#else  
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")  
#endif  
#endif  
```  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Gráfico de hierarquia](../mfc/hierarchy-chart.md)   
 [APIs ANSI preteridas](../mfc/deprecated-ansi-apis.md)

