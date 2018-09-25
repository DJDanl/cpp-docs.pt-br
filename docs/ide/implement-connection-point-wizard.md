---
title: Assistente para Implementação de Ponto de Conexão | Microsoft Docs
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
ms.openlocfilehash: 92312bc130ed24f2aafe2e4b95e2c4bcf6381215
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429663"
---
# <a name="implement-connection-point-wizard"></a>Assistente de Implementação de Pontos de Conexão

Este assistente implementa um ponto de conexão para um objeto COM. Um objeto conectável (ou seja, uma fonte) pode expor um ponto de conexão para suas próprias interfaces ou para qualquer interface de saída. O Visual C++ e o Windows fornecem bibliotecas de tipos que têm interfaces de saída. Cada interface de saída pode ser implementada por um cliente em um objeto (ou seja, um coletor).

Para obter mais informações, confira [Pontos de conexão da ATL](../atl/atl-connection-points.md).

- **Bibliotecas de tipos disponíveis**

   Exibe as bibliotecas de tipos disponíveis que contêm as definições de interface para as quais você pode implementar pontos de conexão. Clique no botão de reticências para localizar um arquivo que contém a biblioteca de tipos a ser usada.

- **Local**

   Exibe o local da biblioteca de tipos atualmente selecionada na lista **Bibliotecas de tipos disponíveis**.

- **Interfaces**

   Exibe as interfaces cujas definições estão contidas na biblioteca de tipos atualmente selecionada na caixa **Bibliotecas de tipos disponíveis**.

   |Botão de transferência|Descrição|
   |---------------------|-----------------|
   |**>**|Adiciona à lista **Implementar pontos de conexão** o nome da interface atualmente selecionado na lista **Interfaces**.|
   |**>>**|Adiciona à lista **Implementar pontos de conexão** todos os nomes de interfaces disponíveis na lista **Interfaces**.|
   |**\<**|Remove o nome da interface atualmente selecionado na lista **Implementar pontos de conexão**.|
   |**\<\<**|Remove todos os nomes de interfaces atualmente relacionados na lista **Implementar pontos de conexão**.|

- **Implementar pontos de conexão**

   Exibe os nomes das interfaces nas quais você implementa pontos de conexão quando clica em **Concluir**.

## <a name="see-also"></a>Consulte também

[Implementando um ponto de conexão](../ide/implementing-a-connection-point-visual-cpp.md)