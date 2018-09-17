---
title: -REBASE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /rebase
dev_langs:
- C++
helpviewer_keywords:
- base addresses [C++]
- -REBASE editbin option
- REBASE editbin option
- DLLs [C++], linking
- executable files [C++], base address
- /REBASE editbin option [C++]
ms.assetid: 3f89d874-af5c-485b-974b-fd205f6e1a4b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a2f226d9f207f6e04feb2b240551cd53cad69a85
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45719154"
---
# <a name="rebase"></a>/REBASE

```
/REBASE[:modifiers]
```

## <a name="remarks"></a>Comentários

Essa opção define os endereços base para os arquivos especificados. EDITBIN atribui novos endereços base em um espaço de endereço adjacente acordo com o tamanho de cada arquivo arredondado até o mais próximo de 64 KB. Para obter detalhes sobre os endereços base, consulte o [endereço Base](../../build/reference/base-base-address.md) (/ BASE) a opção de vinculador.

Especifique o programa arquivos executáveis e DLLs na *arquivos* argumento na linha de comando EDITBIN na ordem em que deverão ser baseada. Opcionalmente, você pode especificar um ou mais *modificadores*, cada um separado por uma vírgula (**,**):

|Modificador|Ação|
|--------------|------------|
|**BASE =**<em>endereço</em>|Fornece um endereço de início para reatribuir endereços base para os arquivos. Especificar *endereço* em decimal ou notação de linguagem C. Se a BASE não for especificada, o endereço de base inicial padrão é 0x400000. Se a busca é usado, BASE devem ser especificados, e *endereço* define o final do intervalo de endereços de base.|
|**BASEFILE**|Cria um arquivo chamado COFFBASE. TXT, que é um arquivo de texto no formato esperado do LINK/opção de BASE.|
|**PARA BAIXO**|Informa ao EDITBIN reatribuir endereços base para baixo de um endereço final. Os arquivos são reatribuídos na ordem especificada, com o primeiro arquivo localizado no endereço mais alto possível abaixo do final do intervalo de endereços. BASE deve ser usada com baixo para garantir que o espaço de endereço suficiente para basear os arquivos. Para determinar o espaço de endereço necessário para os arquivos especificados, executar EDITBIN com /REBASE em arquivos e adicione a 64 KB para o tamanho total exibido.|

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)