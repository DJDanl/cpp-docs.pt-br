---
title: Quais Classes ATL facilitam a contenção de controle ActiveX? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- hosting controls using ATL
- ActiveX control containers [C++], ATL control hosting
ms.assetid: 803a4605-7f4c-4139-8638-49d8783d31b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f024e9929e916e15b110bfc32bc704c4aef755a9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32361931"
---
# <a name="which-atl-classes-facilitate-activex-control-containment"></a>Quais Classes ATL facilitam a contenção de controle ActiveX?
Código de hospedagem de controles da ATL não exige que você usar todas as classes ATL; Você pode simplesmente criar um **"AtlAxWin80"** janela e use a API de hospedagem de controles, se necessário (para obter mais informações, consulte **o que é a API de hospedagem de controles de ATL**. No entanto, as seguintes classes de tornam os recursos de contenção mais fácil de usar.  
  
|Classe|Descrição|  
|-----------|-----------------|  
|[CAxWindow](../atl/reference/caxwindow-class.md)|Encapsula um **"AtlAxWin80"** janela, fornecimento de métodos para criar a janela, criando um controle de e/ou anexando um controle para a janela e recuperando ponteiros de interface no objeto de host.|  
|[CAxWindow2T](../atl/reference/caxwindow2t-class.md)|Encapsula um **"AtlAxWinLic80"** janela, fornecimento de métodos para criar a janela, criando um controle de e/ou anexando um controle licenciado para a janela e recuperando ponteiros de interface no objeto de host.|  
|[CComCompositeControl](../atl/reference/ccomcompositecontrol-class.md)|Atua como uma classe base para classes de controle ActiveX com base em um recurso de caixa de diálogo. Esses controles podem conter outros controles ActiveX.|  
|[CAxDialogImpl](../atl/reference/caxdialogimpl-class.md)|Atua como uma classe base para classes de caixa de diálogo com base em um recurso de caixa de diálogo. Essas caixas de diálogo podem conter controles ActiveX.|  
|[CWindow](../atl/reference/cwindow-class.md)|Fornece um método [GetDlgControl](../atl/reference/cwindow-class.md#getdlgcontrol), que retorna um ponteiro de interface em um controle, dado a ID da sua janela do host. Além disso, os wrappers de API do Windows é exposto pelo `CWindow` geralmente facilitar o gerenciamento de janela.|  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

