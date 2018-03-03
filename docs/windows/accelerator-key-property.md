---
title: Propriedade de chave do acelerador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Key property
ms.assetid: d1570cd9-b414-4cd6-96bd-47c38281eaca
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 365960717f5fe4cedf79615fd3087bc89d6b531c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accelerator-key-property"></a>Propriedade da tecla de aceleração
As seguintes entradas legais para a propriedade de chave na tabela de teclas aceleradoras são:  
  
-   Um inteiro entre 0 e 255 no formato decimal. O valor determina se o valor é tratado como ANSI ou ASCII da seguinte maneira:  
  
    -   Números de dígito sempre são interpretados como a chave correspondente, em vez de valores ASCII ou ANSI.  
  
    -   Valores de 1 a 26, quando precedido com zeros, são interpretados como ^ A-^ Z, que representa o valor ASCII das letras do alfabeto quando pressionada com a tecla CTRL pressionada.  
  
    -   Valores de 27-32 sempre são interpretados como valores de três dígitos decimais 027 ao 032.  
  
    -   Os valores do 033 a 255, precedido por um 0 ou não são interpretados como valores de ANSI.  
  
-   Um caractere único teclado. Letras maiusculas A - Z ou os números 0 - 9 podem ser ASCII ou valores de chave virtuais; qualquer outro caractere só é ASCII.  
  
-   Um caractere único teclado no intervalo de A - Z (maiusculas somente), precedido por um sinal de intercalação (^) (por exemplo, ^ C). Isso insere o valor ASCII da chave quando ela estiver pressionada com a tecla CTRL pressionada.  
  
    > [!NOTE]
    >  Ao inserir um valor ASCII, as opções de propriedade de modificador são limitadas. A única chave de controle disponível para uso é a tecla ALT.  
  
-   Qualquer válido identificador de tecla virtual. A caixa de lista suspensa de chave na tabela de teclas aceleradoras contém uma lista de identificadores de chave virtuais padrão.  
  
    > [!TIP]
    >  Outra maneira de definir uma tecla aceleradora é uma entrada ou várias entradas na tabela de aceleradores de atalho, escolha **próxima chave digitada** no menu de atalho e, em seguida, pressione qualquer uma das chaves ou combinações de teclas no teclado. O **próxima chave digitada** comando também está disponível na **editar** menu.  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Definindo propriedades de acelerador](../windows/setting-accelerator-properties.md)   
 [Editando em uma tabela de aceleradores](../windows/editing-in-an-accelerator-table.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)