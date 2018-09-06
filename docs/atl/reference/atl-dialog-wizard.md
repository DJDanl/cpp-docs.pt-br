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
ms.openlocfilehash: fe3311e46ea28424717a0274fbe9e956610cdc54
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43767706"
---
# <a name="atl-dialog-wizard"></a>Assistente de caixa de diálogo da ATL

Este assistente insere o projeto de um objeto de caixa de diálogo do ATL, derivado de [CAxDialogImpl](../../atl/reference/caxdialogimpl-class.md). Derivado de uma caixa de diálogo de `CAxDialogImpl` podem hospedar controles ActiveX.

O assistente cria um recurso de caixa de diálogo padrão **Okey** e **Cancelar** botões. Você pode editar o recurso de caixa de diálogo e adicionar controles ActiveX usando o [Editor de caixa de diálogo](../../windows/dialog-editor.md) no modo de exibição de recursos.

O assistente insere o arquivo de cabeçalho um [mapa de mensagem](../../atl/message-maps-atl.md) e declarações para lidar com o padrão de eventos de clique. Ver [implementar uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações sobre caixas de diálogo do ATL.

**Nome curto**  
Define o nome abreviado para o objeto de caixa de diálogo do ATL. O nome que você fornece determina o nome de classe e os nomes arquivo (. cpp e. h), a menos que você altere esses campos individualmente.

`Class`  
Define o nome da classe a ser criado. Esse nome se baseia o nome fornecido no **Short name**, precedidos pela 'c', o prefixo típico para um nome de classe.

**Arquivo .h**  
Define o nome do arquivo de cabeçalho para a nova classe do objeto. Por padrão, esse nome se baseia o nome fornecido no **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha, ou para acrescentar a declaração de classe a um arquivo existente. Se você escolher um arquivo existente, o assistente não o salvará no local selecionado até que você clique em **Concluir** no assistente.

O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a declaração de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

**Arquivo .cpp**  
Define o nome do arquivo de implementação para a nova classe do objeto. Por padrão, esse nome se baseia o nome fornecido no **Short name**. Clique no botão de reticências para salvar o nome de arquivo no local de sua escolha. O arquivo não é salvo no local selecionado até que você clique em **Concluir** no assistente.

O assistente não substitui um arquivo. Se você selecionar o nome de um arquivo existente, quando clicar em **Concluir**, o assistente solicitará que você indique se a implementação de classe deve ser acrescentada ao conteúdo do arquivo. Clique em **Sim** para acrescentar o arquivo; clique em **Não** para retornar ao assistente e especificar outro nome de arquivo.

## <a name="see-also"></a>Consulte também

[Caixa de diálogo do ATL](../../atl/reference/adding-an-atl-dialog-box.md)

