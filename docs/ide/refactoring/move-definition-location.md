---
title: Mover Local da Definição | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: c6d507ac-c61e-4da2-95c8-d504b42e2520
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5058e0b3bab1fb5fb5e8d52b55e3fa7c37fd8a4e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46430030"
---
# <a name="move-definition-location"></a>Mover Local da Definição
**O quê:** permite mover imediatamente uma definição de função para o arquivo de cabeçalho correspondente.

**Quando:** você tem uma função que deseja mover para um arquivo de cabeçalho.

**Por quê:** você pode mover a função manualmente, mas esse recurso a moverá automaticamente, criando o arquivo de cabeçalho, se necessário.

**Como:**

1. Coloque o cursor de texto ou do mouse sobre a função para a qual deseja mover.

   ![Código realçado](images/movedefinition_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o menu **Ações Rápidas e Refatorações** e selecione **Mover Local da Definição** no menu de contexto.
   * **Mouse**
     * Clique com o botão direito do mouse, selecione o menu **Ações Rápidas e Refatorações** e selecione **Mover Local da Definição** no menu de contexto.

1. A função será movida para o arquivo de cabeçalho correspondente, que você verá em uma janela pop-up de visualização.  Caso o arquivo de cabeçalho não exista, ele também será criado e colocado no projeto.

   ![Resultado de Criar Declaração/Definição](images/movedefinition_result.png)
