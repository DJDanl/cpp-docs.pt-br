---
title: Como implementar páginas de propriedades
ms.date: 11/04/2016
helpviewer_keywords:
- IPropertyPage2 class
- IPropertyPage class
- property pages, implementing
ms.assetid: 62f29440-33a7-40eb-a1ef-3634c95f640c
ms.openlocfilehash: c4ba69d8421a76a94e4a676cb62ee53936d77da3
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65524578"
---
# <a name="implementing-property-pages"></a>Como implementar páginas de propriedades

::: moniker range="vs-2019"

O assistente de Página de Propriedades da ATL não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="vs-2017"

As páginas de propriedades são objetos COM que implementam a interface `IPropertyPage` ou `IPropertyPage2`. A ATL é compatível com a implementação de páginas de propriedades por meio do [Assistente de Página de Propriedades da ATL](../atl/reference/atl-property-page-wizard.md) na [caixa de diálogo Adicionar Classe](../ide/add-class-dialog-box.md).

Criação de uma página de propriedades usando a ATL:

- Crie ou abra um projeto de servidor DLL (Biblioteca de Vínculo Dinâmico) da ATL.

- Abra a [caixa de diálogo Adicionar Classe](../ide/add-class-dialog-box.md) e selecione **Página de Propriedades da ATL**.

- Verifique se sua página de propriedades é do modelo Apartment Threading (desde que tenha uma interface do usuário).

- Defina o título, a descrição (Doc String) e o arquivo de ajuda a ser associado à sua página.

- Adicione controles ao recurso de caixa de diálogo gerado para atuar como a interface do usuário de sua página de propriedades.

- Responda às alterações na interface do usuário da sua página para executar a validação, atualizar o site de página ou atualizar os objetos associados à sua página. Especificamente, chame [IPropertyPageImpl::SetDirty](../atl/reference/ipropertypageimpl-class.md#setdirty) quando o usuário alterar a página de propriedades.

- Se desejar, substitua os métodos `IPropertyPageImpl` usando as diretrizes abaixo.

   |Método IPropertyPageImpl|Substitua quando desejar...|Observações|
   |------------------------------|----------------------------------|-----------|
   |[SetObjects](../atl/reference/ipropertypageimpl-class.md#setobjects)|Execute as verificações de integridade básicas no número de objetos que estão sendo passados para sua página e as interfaces com as quais eles são compatíveis.|Execute o seu próprio código antes de chamar a implementação da classe base. Se os objetos que estão sendo definidos não estiverem em conformidade com as suas expectativas, você deverá interromper a chamada assim que possível.|
   |[Activate](../atl/reference/ipropertypageimpl-class.md#activate)|Inicialize a interface do usuário da sua página (por exemplo, defina os controles da caixa de diálogo com valores da propriedade atuais de objetos, crie controles dinamicamente ou execute outras inicializações).|Chame a implementação da classe base antes do código para que a classe base tenha a oportunidade de criar a janela de diálogo e todos os controles antes de você tentar atualizá-los.|
   |[Apply](../atl/reference/ipropertypageimpl-class.md#apply)|Valide as configurações de propriedade e atualize os objetos.|Não é necessário chamar a implementação da classe base, uma vez que ela não tem função nenhuma além de rastrear a chamada.|
   |[Deactivate](../atl/reference/ipropertypageimpl-class.md#deactivate)|Limpe os itens relacionados à janela.|A implementação da classe base destrói a caixa de diálogo que representa a página de propriedades. Se você precisar limpar antes que a caixa de diálogo seja destruída, será preciso adicionar seu código antes de chamar a classe base.|

Confira um exemplo de implementação de página de propriedades em [Exemplo: implementação de uma página de propriedades](../atl/example-implementing-a-property-page.md).

> [!NOTE]
> Se quiser hospedar controles ActiveX em sua página de propriedades, você precisará alterar a derivação da sua classe gerada pelo assistente. Substitua **CDialogImpl\<CYourClass >** por **CAxDialogImpl\<CYourClass >** na lista de classes base.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../atl/atl-com-property-pages.md)<br/>
[Exemplo de páginas ATL](../overview/visual-cpp-samples.md)
