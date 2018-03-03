---
title: "Assistente de ponto de Conexão de implementação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.codewiz.impl.cp.overview
dev_langs:
- C++
helpviewer_keywords:
- Implement Connection Point Wizard [C++]
ms.assetid: c117f6c6-30f0-4adb-82b4-b1f34e0f0fa8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f29b4f25d937c2f538373ff85819f7315150e712
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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