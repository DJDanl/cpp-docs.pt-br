---
title: Assistente de caixa de diálogo do ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.dlg.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding dialog resources
- ATL Dialog Wizard
ms.assetid: b0b9ace5-83c9-40d3-82c3-eb6293f10583
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e2d78f0a41edca44f8841d701cc87975c551466
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358000"
---
# <a name="atl-dialog-wizard"></a>Assistente de caixa de diálogo do ATL
Este assistente insere o projeto de um objeto de caixa de diálogo do ATL, derivado de [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Uma caixa de diálogo derivado `CAxDialogImpl` pode hospedar controles ActiveX.  
  
 O assistente cria um recurso de caixa de diálogo padrão **Okey** e **Cancelar** botões. Você pode editar o recurso de caixa de diálogo e adicionar controles ActiveX usando o [Editor de caixa de diálogo](../../windows/dialog-editor.md) no modo de exibição de recursos.  
  
 O assistente Inserir no arquivo de cabeçalho um [mapa de mensagem](../../atl/message-maps-atl.md) e eventos de clique de declarações para lidar com o padrão. Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações sobre caixas de diálogo da ATL.  
  
 **Nome curto**  
 Define o nome abreviado para o objeto de caixa de diálogo da ATL. O nome que você fornecer determina o nome da classe e os nomes de (. cpp e. h) de arquivo, a menos que você altere os campos individualmente.  
  
 `Class`  
 Define o nome da classe a ser criado. Este nome é baseado no nome que você fornecer em **nome curto**, precedidas por "C", o prefixo comum para um nome de classe.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará o local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Caixa de diálogo do ATL](../../atl/reference/adding-an-atl-dialog-box.md)

