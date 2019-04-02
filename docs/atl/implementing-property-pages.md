---
title: Implementação de páginas de propriedade
ms.date: 11/04/2016
helpviewer_keywords:
- IPropertyPage2 class
- IPropertyPage class
- property pages, implementing
ms.assetid: 62f29440-33a7-40eb-a1ef-3634c95f640c
ms.openlocfilehash: 8999f6469e420fa86cb1267675f10dc173d45ff0
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58776241"
---
# <a name="implementing-property-pages"></a>Implementação de páginas de propriedade

Páginas de propriedades são COM objetos que implementam o `IPropertyPage` ou `IPropertyPage2` interface. ATL fornece suporte para a implementação de páginas de propriedade por meio de [Assistente de página de propriedades ATL](../atl/reference/atl-property-page-wizard.md) na [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md).

Para criar uma página de propriedades usando ATL:

- Crie ou abra um projeto do servidor ATL Dynamic-link library (DLL).

- Abra o [caixa de diálogo Adicionar classe](../ide/add-class-dialog-box.md) e selecione **página de propriedades ATL**.

- Verifique se que sua página de propriedades é apartment threaded (já que ele tem uma interface do usuário).

- Defina o título, descrição (cadeia de caracteres Doc) e o arquivo de ajuda a ser associado à sua página.

- Adicione controles para o recurso de caixa de diálogo gerado para atuar como a interface do usuário da sua página de propriedades.

- Responda a alterações na interface do usuário da sua página para executar a validação, atualize o site de página ou atualizar os objetos associados à sua página. Em particular, chame [IPropertyPageImpl::SetDirty](../atl/reference/ipropertypageimpl-class.md#setdirty) quando o usuário faz alterações para a página de propriedades.

- Opcionalmente, substituir o `IPropertyPageImpl` métodos usando as diretrizes abaixo.

   |Método IPropertyPageImpl|Substitua quando quiser...|Observações|
   |------------------------------|----------------------------------|-----------|
   |[SetObjects](../atl/reference/ipropertypageimpl-class.md#setobjects)|Execute as verificações de integridade básicas sobre o número de objetos que estão sendo passados para sua página e as interfaces que dão suporte a eles.|Execute seu próprio código antes de chamar a implementação da classe base. Se os objetos que está sendo definidos não atenderem suas expectativas, você deve fazer a chamada assim que possível.|
   |[Ativar](../atl/reference/ipropertypageimpl-class.md#activate)|Inicialize a interface do usuário da sua página (por exemplo, defina os controles de caixa de diálogo com valores da propriedade atual de objetos, criar controles dinamicamente ou executar outras inicializações).|Chame a implementação de classe base antes de seu código para que a classe base tenha a oportunidade de criar a janela de diálogo e todos os controles, antes de tentar atualizá-los.|
   |[Apply](../atl/reference/ipropertypageimpl-class.md#apply)|Valide as configurações de propriedade e atualize os objetos.|Não é necessário chamar a implementação da classe base, pois ele não faz nada além de rastreamento de chamada.|
   |[Desativar](../atl/reference/ipropertypageimpl-class.md#deactivate)|Limpe itens relacionados a janela.|A implementação da classe base destrói a caixa de diálogo que representa a página de propriedades. Se você precisar limpar antes que a caixa de diálogo é destruída, você deve adicionar seu código antes de chamar a classe base.|

Para uma implementação de página de propriedade de exemplo, consulte [exemplo: Implementando uma página de propriedades](../atl/example-implementing-a-property-page.md).

> [!NOTE]
> Se você quiser hospedar controles ActiveX em sua página de propriedade, você precisará alterar a derivação da classe gerada pelo assistente. Substitua **CDialogImpl\<CYourClass >** com **CAxDialogImpl\<CYourClass >** na lista de classes base.

## <a name="see-also"></a>Consulte também

[Páginas de propriedade](../atl/atl-com-property-pages.md)<br/>
[Exemplo de ATLPages](../overview/visual-cpp-samples.md)
