---
title: Assistente de ponto de Conexão de implementação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.codewiz.impl.cp.overview
dev_langs:
- C++
helpviewer_keywords:
- Implement Connection Point Wizard [C++]
ms.assetid: c117f6c6-30f0-4adb-82b4-b1f34e0f0fa8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef2f7efa92de3714170e403ea50b5f486c8367d6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="implement-connection-point-wizard"></a>Assistente de Implementação de Pontos de Conexão
Este assistente implementa um ponto de conexão para um objeto COM. Um objeto conectável (ou seja, uma fonte) pode expor um ponto de conexão para suas próprias interfaces ou para qualquer interface de saída. Visual C++ e o Windows fornecem bibliotecas de tipo que tenham interfaces de saída. Cada interface de saída pode ser implementado por um cliente em um objeto (ou seja, um coletor).  
  
 Para obter mais informações, consulte [pontos de Conexão de ATL](../atl/atl-connection-points.md).  
  
 **Bibliotecas de tipo disponível**  
 Exibe as bibliotecas de tipo disponível que contém as definições de interface para o qual você pode implementar pontos de conexão. Clique no botão de reticências para localizar um arquivo que contém a biblioteca de tipo a ser usado.  
  
 **Local**  
 Exibe o local da biblioteca de tipo selecionado no momento o **bibliotecas de tipo disponível** lista.  
  
 **Interfaces**  
 Exibe as interfaces cujas definições estão contidas na biblioteca de tipos selecionada no momento o **bibliotecas de tipo disponível** caixa.  
  
|Botão de transferência|Descrição|  
|---------------------|-----------------|  
|**>**|Adiciona o **implementar pontos de conexão** lista o nome da interface selecionado no momento o **Interfaces** lista.|  
|**>>**|Adiciona o **implementar pontos de conexão** lista todos os nomes de interface disponíveis no **Interfaces** lista.|  
|**<**|Remove o nome da interface selecionado no momento o **implementar pontos de conexão** lista.|  
|**<<**|Remove todos os nomes listados no momento da interface de **implementar pontos de conexão** lista.|  
  
 **Implementar pontos de conexão**  
 Exibe os nomes das interfaces para os quais você implementar pontos de conexão quando você clica em **concluir**.  
  
## <a name="see-also"></a>Consulte também  
 [Implementando um ponto de Conexão](../ide/implementing-a-connection-point-visual-cpp.md)