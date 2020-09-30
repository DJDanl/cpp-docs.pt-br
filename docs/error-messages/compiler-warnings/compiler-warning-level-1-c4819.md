---
title: Aviso do compilador (nível 1) C4819
ms.date: 04/08/2019
f1_keywords:
- C4819
helpviewer_keywords:
- C4819
ms.assetid: c0316e85-249c-414d-9df0-622d077c6bc2
ms.openlocfilehash: f81a4f44a489e2e4c5bd5c063d922129581819f9
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509366"
---
# <a name="compiler-warning-level-1-c4819"></a>Aviso do compilador (nível 1) C4819

> O arquivo contém um caractere que não pode ser representado na página de código atual (*número*). Salve o arquivo no formato Unicode para evitar a perda de dados.

C4819 ocorre quando você compila um arquivo de origem ANSI em um sistema usando uma página de código que não pode representar todos os caracteres no arquivo.

Há várias maneiras de resolver o C4819. Uma maneira simples é remover o caractere incorreto, se você não precisar dele, por exemplo, se ele estiver em um comentário. Você pode definir a página de código do sistema no painel de controle para uma que dê suporte ao conjunto de caracteres usado pelo seu código-fonte. Você pode usar [sequências de escape](../../c-language/escape-sequences.md) Unicode para criar caracteres ou cadeias que usam apenas o conjunto de caracteres ANSI básico em seu código-fonte. Por fim, você pode salvar o arquivo em um formato Unicode com uma assinatura, também conhecida como uma BOM (marca de ordem de byte).

Para salvar um arquivo no formato Unicode, no Visual Studio, escolha **arquivo**  >  **salvar como**. Na caixa de diálogo **salvar arquivo como** , selecione a lista suspensa no botão **salvar** e escolha **salvar com codificação**. Se você salvar o mesmo nome de arquivo, talvez seja necessário confirmar que deseja substituir o arquivo. Na caixa de diálogo **Opções avançadas de salvamento** , escolha uma codificação que possa representar todos os caracteres no arquivo — por exemplo, **Unicode (UTF-8 com assinatura)-CodePage 65001**– e escolha **OK**.
