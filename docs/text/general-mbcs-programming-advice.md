---
title: Aviso de programação MBCS geral | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- _mbcs
dev_langs:
- C++
helpviewer_keywords:
- MBCS [C++], dialog box fonts
- MS Shell Dlg
- MBCS [C++], programming
- dialog boxes [C++], fonts
ms.assetid: 7b541235-f3e5-4af0-b2c2-a0112cd5fbfb
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ab2b67c82a04a0c355761ec6572a9718d03c4666
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33855793"
---
# <a name="general-mbcs-programming-advice"></a>Aviso de programação MBCS geral
Use as dicas a seguir:  
  
-   Para obter flexibilidade, usar macros de tempo de execução, como `_tcschr` e `_tcscpy` quando possível. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
-   Use o tempo de execução C `_getmbcp` função para obter informações sobre a página de código atual.  
  
-   Não reutilize os recursos de cadeia de caracteres. Dependendo do idioma de destino, uma determinada cadeia de caracteres pode ter um significado diferente quando convertido. Por exemplo, menu principal "File" do aplicativo pode traduzir diferente de cadeia de caracteres "File" em uma caixa de diálogo. Se você precisar usar mais de uma cadeia de caracteres com o mesmo nome, use IDs de cadeia de caracteres diferente para cada um.  
  
-   Você talvez queira descobrir se seu aplicativo está sendo executado em um sistema operacional habilitado MBCS. Para fazer isso, defina um sinalizador no início do programa; Não confie em chamadas de API.  
  
-   Ao criar caixas de diálogo, permitir que cerca de 30% espaço extra no final de controles de texto estático para conversão MBCS.  
  
-   Tenha cuidado ao selecionar fontes para seu aplicativo, porque algumas fontes não estão disponíveis em todos os sistemas.  
  
-   Ao selecionar a fonte das caixas de diálogo, use [MS Shell Dlg](http://msdn.microsoft.com/library/windows/desktop/dd374112) em vez de MS Sans Serif ou Helvetica. MS Shell Dlg é substituído com a fonte correta pelo sistema antes de criar a caixa de diálogo. Usar o MS Shell Dlg garante que as alterações no sistema operacional para lidar com essa fonte estarão automaticamente disponíveis. (MFC substitui MS Shell Dlg com o DEFAULT_GUI_FONT ou a fonte do sistema no Windows 95, Windows 98 e Windows NT 4 porque esses sistemas não tratar MS Shell Dlg corretamente.)  
  
-   Ao projetar seu aplicativo, decida quais cadeias de caracteres podem ser localizadas. Em caso de dúvida, suponha que qualquer cadeia de caracteres fornecida será localizada. Como tal, não misture cadeias de caracteres que podem ser localizadas com aqueles que não é possível.  
  
## <a name="see-also"></a>Consulte também  
 [Dicas de programação MBCS](../text/mbcs-programming-tips.md)   
 [Incrementando e decrementando ponteiros](../text/incrementing-and-decrementing-pointers.md)