---
title: Mover Local da Definição
ms.date: 11/16/2016
ms.assetid: c6d507ac-c61e-4da2-95c8-d504b42e2520
ms.openlocfilehash: 7957e18732dfae92b7b3ae9cf7ecea441fc3a6b4
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693199"
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
