---
title: "Opções de Link | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- nothrownew.obj
- newmode.obj
- noenv.obj
- psetargv.obj
- loosefpmath.obj
- smallheap.obj
- fp10.obj
- nochkclr.obj
- chkstk.obj
- pcommode.obj
- pnoenv.obj
- link options [C++]
- invalidcontinue.obj
- pnothrownew.obj
- pwsetargv.obj
- pinvalidcontinue.obj
- wsetargv.obj
- binmode.obj
- setargv.obj
- noarg.obj
- pnewmode.obj
- commode.obj
- pthreadlocale.obj
- pbinmode.obj
- threadlocale.obj
- pnoarg.obj
ms.assetid: 05b5a77b-9dd1-494b-ae46-314598c770bb
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Human Translation
ms.sourcegitcommit: cc82b83860786ffc3f0aee73ede18ecadef16a7a
ms.openlocfilehash: 3747170eb13e1b6fe5d489bc6cfdcf4c24195606
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="link-options"></a>Opções de link
O diretório lib CRT inclui vários arquivos de objeto pequenos que habilitam recursos específicos de CRT sem qualquer alteração de código. Eles são chamados de “opções de link”, pois você só precisa adicioná-los à linha de comando do vinculador para usá-los.  
  
 Versões do modo puro existem, mas são preteridas no Visual Studio 2015. Use as versões regulares para códigos nativos e /clr; use as versões puras (com prefixo “p”) para o modo /clr:pure. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
|Nativo e /clr|Modo puro|Descrição|  
|----------------------|---------------|-----------------|  
|binmode.obj|pbinmode.obj|Define o modo padrão de conversão de arquivo como binário. Consulte [_fmode](../c-runtime-library/fmode.md).|  
|chkstk.obj|N/D|Oferece verificação de pilha e suporte a alloca quando o CRT não está sendo usado.|  
|commode.obj|pcommode.obj|Define o sinalizador de confirmação global como "confirmação". Consulte [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md) e [fopen_s, _wfopen_s](../c-runtime-library/reference/fopen-s-wfopen-s.md).|  
|fp10.obj|N/D|Altera o controle de precisão padrão para 64 bits. Consulte [Suporte de Ponto Flutuante](../c-runtime-library/floating-point-support.md).|  
|invalidcontinue.obj|pinvalidcontinue.obj|Define um manipulador de parâmetro inválido padrão que não realiza nenhuma atividade, isto é, parâmetros inválidos passados para funções CRT serão definidos como errno e retornarão um resultado de erro.|  
|loosefpmath.obj|N/D|Garante que códigos de ponto flutuante tolerem valores desnormalizados.|  
|newmode.obj|pnewmode.obj|Faz com que o [malloc](../c-runtime-library/reference/malloc.md) chame o novo manipulador em caso de falha. Consulte [_set_new_mode](../c-runtime-library/reference/set-new-mode.md), [_set_new_handler](../c-runtime-library/reference/set-new-handler.md), [calloc](../c-runtime-library/reference/calloc.md) e [realloc](../c-runtime-library/reference/realloc.md).|  
|noarg.obj|pnoarg.obj|Desabilita todo o processamento de argc e argv.|  
|nochkclr.obj|N/D|Não agir. Remover do seu projeto.|  
|noenv.obj|pnoenv.obj|Desabilita a criação de um ambiente em cache para o CRT.|  
|nothrownew.obj|pnothrownew.obj|Habilita a versão de não lançamento de new no CRT. Consulte [Operadores new e delete](../cpp/new-and-delete-operators.md).|  
|setargv.obj|psetargv.obj|Habilita a expansão de curinga da linha de comando. Consulte [Expandindo Argumentos de Curinga](../c-language/expanding-wildcard-arguments.md).|  
|threadlocale.obj|pthreadlocale.obj|Habilita a localidade por thread para todos os novos threads por padrão.|  
|wsetargv.obj|pwsetargv.obj|Habilita a expansão de curinga da linha de comando. Consulte [Expandindo Argumentos de Curinga](../c-language/expanding-wildcard-arguments.md).|  
  
## <a name="see-also"></a>Consulte também  
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
