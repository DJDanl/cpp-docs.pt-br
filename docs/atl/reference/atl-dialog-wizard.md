---
title: "Assistente de caixa de diálogo do ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.dlg.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding dialog resources
- ATL Dialog Wizard
ms.assetid: b0b9ace5-83c9-40d3-82c3-eb6293f10583
caps.latest.revision: 10
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 4fafe461008e3545243d693e0d9e34acd57163e0
ms.openlocfilehash: 43540b1b86dbbf1777e7d5a7f6d8dec5dc618334
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atl-dialog-wizard"></a>Assistente de Caixa de Diálogo da ATL
Este assistente insere o projeto de um objeto de caixa de diálogo do ATL, derivado de [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Uma caixa de diálogo derivada de `CAxDialogImpl` podem hospedar controles ActiveX.  
  
 O assistente cria um recurso de caixa de diálogo padrão **Okey** e **Cancelar** botões. Você pode editar o recurso da caixa de diálogo e adicionar controles ActiveX usando o [caixa de diálogo Editor](../../windows/dialog-editor.md) na exibição de recurso.  
  
 O assistente insere o arquivo de cabeçalho um [mapa da mensagem](../../atl/message-maps-atl.md) e eventos de clique de declarações para lidar com o padrão. Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações sobre caixas de diálogo do ATL.  
  
 **Nome curto**  
 Define o nome abreviado para o objeto de caixa de diálogo do ATL. O nome que você fornece determina o nome da classe e nomes arquivo (. cpp e. h), a menos que você altere os campos individualmente.  
  
 `Class`  
 Define o nome da classe a ser criado. Esse nome é baseado no nome fornecidas nos **nome curto**, precedido por 'c'o prefixo típico para um nome de classe.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto. Por padrão, esse nome se baseia o nome fornecido no **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a nova classe de objeto. Por padrão, esse nome se baseia o nome fornecido no **nome curto**. Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Caixa de diálogo do ATL](../../atl/reference/adding-an-atl-dialog-box.md)


