---
title: Vantagens e desvantagens do método usado para vincular ao CRT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- _ATL_MIN_CRT macro
ms.assetid: 49b485f7-9487-49e4-b12a-0f710b620e2b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4b90259a942ea785cfbfee4bfda803d9d7b568d4
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43753871"
---
# <a name="benefits-and-tradeoffs-of-the-method-used-to-link-to-the-crt"></a>Vantagens e desvantagens do método usado para vincular ao CRT

Seu projeto pode vincular com o CRT dinamicamente ou estaticamente. A tabela a seguir descreve os benefícios e compensações envolvidas na escolha de qual método usar.

|Método|Benefício|Compensação|
|------------|-------------|--------------|
|Vincular estaticamente ao CRT<br /><br /> (**Biblioteca de tempo de execução** definido como **Single-threaded**)|A DLL do CRT não é necessário no sistema em que a imagem será executado.|Cerca de 25 mil do código de inicialização é adicionado à sua imagem, aumentar substancialmente o seu tamanho.|
|Vincular dinamicamente ao CRT<br /><br /> (**Biblioteca de tempo de execução** definido como **multi-threaded**)|Sua imagem não exige o código de inicialização do CRT, portanto, é muito menor.|A DLL do CRT deve ser no sistema executando a imagem.|

O tópico [vinculando ao CRT em seu projeto de ATL](../atl/linking-to-the-crt-in-your-atl-project.md) discute como selecionar a maneira na qual deseja vincular ao CRT.

## <a name="see-also"></a>Consulte também

[Programando com código de tempo de execução de C e ATL](../atl/programming-with-atl-and-c-run-time-code.md)   
[DLLs e comportamento da biblioteca em tempo de execução Visual C++](../build/run-time-library-behavior.md)   
[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)

