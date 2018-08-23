---
title: Propriedade de chave de acelerador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Key property
ms.assetid: d1570cd9-b414-4cd6-96bd-47c38281eaca
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 162cb774e985d490385c68bebab01f48222b3616
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42598311"
---
# <a name="accelerator-key-property"></a>Propriedade da tecla de aceleração

As seguintes entradas legais para a propriedade de chave na tabela de aceleradores são:

- Um inteiro entre 0 e 255 no formato decimal. O valor determina se o valor é tratado como ASCII ou ANSI da seguinte maneira:

   - Números de dígito único são sempre interpretados como a chave correspondente, em vez de valores ASCII ou ANSI.

   - Valores de 1 a 26, quando precedido com zeros, são interpretados como ^ A até ^ Z, que representa o valor de ASCII das letras do alfabeto quando pressionado com o **Ctrl** tecla pressionada.

   - Valores de 27 32 sempre são interpretados como valores de três dígitos decimais 027 por meio de 032.

   - Os valores do 033 a 255, precedido por 0 ou não são interpretados como valores de ANSI.

- Um caractere de teclado único. Letras maiusculas A - Z ou os números 0 - 9 podem ser ASCII ou valores de chave virtuais; qualquer outro caractere só é ASCII.

- Um caractere de teclado único no intervalo A - Z (apenas maiusculo), precedido por um acento circunflexo (^) (por exemplo, ^ C). Isso insere o valor de ASCII da chave quando ela estiver pressionada com a **Ctrl** tecla pressionada.

   > [!NOTE]
   > Ao inserir um valor de ASCII, as opções de propriedade de modificador são limitadas. É a única chave de controle disponível para uso a **Alt** chave.

- Qualquer válido identificador de chave virtual. A caixa de lista suspensa de chave na tabela de acelerador contém uma lista de identificadores de chave virtuais padrão.

   > [!TIP]
   > Outra maneira de definir uma tecla aceleradora é uma entrada ou várias entradas na tabela de aceleradores de direito, clique em **próxima chave digitada** no menu de atalho e, em seguida, pressione qualquer uma das chaves ou combinações de teclas no teclado. O **próxima chave digitada** comando também está disponível na **editar** menu.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Configurando propriedades do acelerador](../windows/setting-accelerator-properties.md)  
[Editando em uma tabela de aceleradores](../windows/editing-in-an-accelerator-table.md)  
[Editor de aceleradores](../windows/accelerator-editor.md)