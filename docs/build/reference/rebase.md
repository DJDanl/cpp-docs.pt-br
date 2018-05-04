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
ms.openlocfilehash: 4a5e2b68768b01d71532c358a14c53d8a033e1ed
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="rebase"></a>/REBASE
```  
/REBASE[:modifiers]  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção define os endereços de base para os arquivos especificados. EDITBIN atribui novos endereços de base em um espaço de endereço de contígua de acordo com o tamanho de cada arquivo arredondado até o mais próximo de 64 KB. Para obter detalhes sobre os endereços de base, consulte o [endereço Base](../../build/reference/base-base-address.md) (/ BASE) a opção de vinculador.  
  
 Especifique o programa arquivos executáveis e DLLs do *arquivos* argumento na linha de comando EDITBIN na ordem nos quais eles estão se basear. Opcionalmente, você pode especificar um ou mais *modificadores*, cada um separado por uma vírgula (**,**):  
  
|Modificador|Ação|  
|--------------|------------|  
|BASE **= * endereço*|Fornece um endereço de início para reatribuir endereços base para os arquivos. Especifique *endereço* em decimal ou notação de linguagem C. Se a BASE não for especificada, o padrão de endereço de base inicial é 0x400000. Deve ser especificado se é usada, BASE, e *endereço* define o final do intervalo de endereços base.|  
|BASEFILE|Cria um arquivo chamado COFFBASE. TXT, que é um arquivo de texto no formato esperado pelo LINK/opção de BASE.|  
|PARA BAIXO|Informa EDITBIN reatribuir endereços base para baixo de um endereço final. Os arquivos são reatribuídos na ordem especificada, com o primeiro arquivo localizado no endereço mais alto possível ao final do intervalo de endereços. BASE deve ser usada com baixo para garantir o espaço de endereço suficiente para basear os arquivos. Para determinar o espaço de endereço necessário para os arquivos especificados, executar EDITBIN com /REBASE em arquivos e adicionar 64 KB para o tamanho total exibido.|  
  
## <a name="see-also"></a>Consulte também  
 [Opções de EDITBIN](../../build/reference/editbin-options.md)