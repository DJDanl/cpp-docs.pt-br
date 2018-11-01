---
title: Alterando um símbolo&#39;s de valor numérico
ms.date: 11/04/2016
f1_keywords:
- vc.editors.symbol.changing.value
helpviewer_keywords:
- numeric values
- symbols [C++], numeric values
- numeric values, changing symbols
ms.assetid: 468e903b-9c07-4251-ae09-3b6cb754cc2b
ms.openlocfilehash: 9013ce886b1e596a858321b32249d885d03015ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50629834"
---
# <a name="changing-a-symbol39s-numeric-value"></a>Alterando um símbolo&#39;s de valor numérico

Símbolos associados com um único recurso, você pode usar o [janela de propriedades](/visualstudio/ide/reference/properties-window) para alterar o valor do símbolo. Você pode usar o [caixa de diálogo símbolos de recurso](../windows/resource-symbols-dialog-box.md) para alterar o valor de símbolos que não estão atribuídos a um recurso. Para obter mais informações, consulte [alterando símbolos não atribuídos](../windows/changing-unassigned-symbols.md).

### <a name="to-change-a-symbol-value-assigned-to-a-single-resource-or-object"></a>Para alterar um valor de símbolo atribuído a um único recurso ou objeto

1. Na [exibição de recurso](../windows/resource-view-window.md), selecione o recurso.

   > [!NOTE]
   > Se seu projeto já não contiver um arquivo. RC, consulte [criando um novo arquivo de Script de recurso](../windows/how-to-create-a-resource-script-file.md).

2. No **propriedades** , digite o nome do símbolo seguido por um sinal de igual e um número inteiro na **ID** caixa, por exemplo:

    ```
    IDC_EDITNAME=5100
    ```

O novo valor é armazenado no arquivo de cabeçalho de símbolo na próxima vez que você salvar o projeto. Somente o nome do símbolo permanece visível na caixa ID. o sinal de igual e o valor não são exibidos depois que eles sejam validados.

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recurso a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir recursos cadeias de caracteres de propriedades.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Restrições de valor de símbolo](../windows/symbol-value-restrictions.md)<br/>
[IDs de símbolos predefinidos](../windows/predefined-symbol-ids.md)