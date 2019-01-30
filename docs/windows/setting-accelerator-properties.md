---
title: Configurando propriedades do acelerador (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- accelerator properties
- properties [C++], accelerator properties
- Type property
- Key property
- Modifier property
- VIRTKEY
- Key property
- ID property
ms.assetid: 0fce9156-3025-4e18-b034-e219a4c65812
ms.openlocfilehash: e1fac31635b7ccc09f9c184cf734fa4f7717cb97
ms.sourcegitcommit: 5beace7dcc6bf0e8b8cc96a930e7424f9daa05cb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2019
ms.locfileid: "55232130"
---
# <a name="setting-accelerator-properties"></a>Configurando propriedades do acelerador

Você pode definir propriedades do acelerador [janela de propriedades](/visualstudio/ide/reference/properties-window) a qualquer momento. Você também pode usar o [editor de aceleradores](../windows/accelerator-editor.md) para modificar as propriedades de acelerador na tabela de acelerador. As alterações feitas usando o **propriedades** janela ou o **Accelerator** editor tem o mesmo resultado: as edições são refletidas imediatamente na tabela de aceleradores.

## <a name="id-property"></a>Propriedade ID

O **ID** propriedade faz referência a cada entrada de tabela do acelerador no código do programa. Essa entrada é o valor do comando que o programa receberá quando um usuário pressiona a tecla de atalho ou uma combinação de teclas. Para tornar um acelerador o mesmo que um item de menu, verifique suas IDs o mesmo (desde que a ID da tabela de Aceleradores é igual à ID do recurso de menu).

Há três propriedades para cada ID do acelerador: o **modificador** propriedade, o **chave** propriedade e o **tipo** propriedade.

## <a name="modifier-property"></a>Propriedade de Modificador

O **modificador** propriedade define o controle de combinações de teclas para o acelerador.

> [!NOTE]
> No **propriedades** janela, essa propriedade é exibida como três separado **booliano** propriedades, que pode ser controlado de forma independente: **ALT**, **Ctrl**, e **Shift**.

A seguir estão as entradas legais para o **modificador** propriedade na tabela de acelerador:

   |Valor|Descrição|
   |-----------|-----------------|
   |**Nenhum**|Usuário pressiona apenas o **chave** valor. Esse valor com mais eficiência é usado com os valores de ASCII/ANSI 001 a 026, que é interpretado como ^ A até ^ Z (**Ctrl + T** por meio **Ctrl + Z**).|
   |**Alt**|O usuário deve pressionar o **Alt** chave antes do **chave** valor.|
   |**Ctrl**|O usuário deve pressionar o **Ctrl** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|
   |**Shift**|O usuário deve pressionar o **Shift** chave antes do **chave** valor.|
   |**Ctrl+Alt**|O usuário deve pressionar o **Ctrl** chave e o **Alt** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|
   |**Ctrl+Shift**|O usuário deve pressionar o **Ctrl** chave e o **Shift** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|
   |**Alt+Shift**|O usuário deve pressionar o **Alt** chave e o **Shift** chave antes do **chave** valor. Não é válido com o tipo de ASCII.|
   |**Ctrl+Alt+Shift**|O usuário deve pressionar **Ctrl**, **Alt**, e **Shift** antes do **chave** valor. Não é válido com o tipo de ASCII.|

## <a name="key-property"></a>Propriedade de chave

O **chave** propriedade define a chave real a ser usado como o acelerador.

A seguir estão as entradas legais para o **chave** propriedade na tabela de acelerador:

   |Valor|Descrição|
   |-----------|-----------------|
   |Um inteiro entre 0 e 255 no formato decimal.|O valor determina se o valor é tratado como ASCII ou ANSI da seguinte maneira:<br/><br/>-Números de dígito sempre são interpretados como a chave correspondente, em vez de valores ASCII ou ANSI.<br/>-Valores de 1 a 26, quando precedido com zeros, são interpretados como ^ A até ^ Z, que representa o valor de ASCII das letras do alfabeto quando pressionado com o **Ctrl** tecla pressionada.<br/>-Valores de 27 32 sempre são interpretados como valores de três dígitos decimais 027 por meio de 032.<br/>-Valores do 033 a 255, precedido por 0 ou não são interpretados como valores de ANSI.|
   |Um caractere de teclado único.|Letras maiusculas A - Z ou os números 0 - 9 podem ser ASCII ou valores de chave virtuais; qualquer outro caractere só é ASCII.|
   |Um caractere de teclado único no intervalo A - Z (apenas maiusculo), precedido por um acento circunflexo (^) (por exemplo, ^ C).|Essa opção insere o valor de ASCII da chave quando ela estiver pressionada com a **Ctrl** tecla pressionada.|
   |Qualquer válido identificador de chave virtual.|A caixa de lista suspensa de chave na tabela de acelerador contém uma lista de identificadores de chave virtuais padrão.|

> [!NOTE]
> Ao inserir um valor de ASCII, as opções de propriedade de modificador são limitadas. É a única chave de controle disponível para uso a **Alt** chave.

> [!TIP]
> Outra maneira de definir uma tecla aceleradora é uma entrada ou várias entradas na tabela de aceleradores de direito, clique em **próxima chave digitada** no menu de atalho e, em seguida, pressione qualquer uma das chaves ou combinações de teclas no teclado. O **próxima chave digitada** comando também está disponível na **editar** menu.

## <a name="type-property"></a>Tipo de propriedade

O **tipo** propriedade determina se a combinação de teclas de atalho associada com a ID do acelerador é interpretada como um valor de chave ASCII/ANSI ou uma combinação de chave virtual (VIRTKEY).

- Se o **tipo** propriedade é ASCII, o **modificador** propriedade só pode ser `None` ou `Alt`, ou pode ter um acelerador que usa o **Ctrl** (da chave especificado precedendo a chave com um `^`).

- Se o **tipo** propriedade é VIRTKEY, qualquer combinação de `Modifier` e `Key` valores é válido.

> [!NOTE]
> Se você quiser inserir um valor para a tabela de Aceleradores e têm o valor a ser tratado como ASCII/ANSI, basta clicar o **tipo** para a entrada na tabela e selecione ASCII na lista suspensa. No entanto, se você usar o **próxima chave digitada** comando (**editar** menu) para especificar o `Key`, você deve alterar o **tipo** propriedade de VIRTKEY para ASCII *antes de* inserindo o `Key` código.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Editando em uma tabela de aceleradores](../windows/editing-in-an-accelerator-table.md)<br/>
[Teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
