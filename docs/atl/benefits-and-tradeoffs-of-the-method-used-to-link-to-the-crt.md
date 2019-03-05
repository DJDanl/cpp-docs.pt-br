---
title: Vantagens e desvantagens do método usado para vincular ao CRT
ms.date: 11/04/2016
helpviewer_keywords:
- _ATL_MIN_CRT macro
ms.assetid: 49b485f7-9487-49e4-b12a-0f710b620e2b
ms.openlocfilehash: bc322c704374374d6e7c075dbf466fc2b038b0ba
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57283209"
---
# <a name="benefits-and-tradeoffs-of-the-method-used-to-link-to-the-crt"></a>Vantagens e desvantagens do método usado para vincular ao CRT

Seu projeto pode vincular com o CRT dinamicamente ou estaticamente. A tabela a seguir descreve os benefícios e compensações envolvidas na escolha de qual método usar.

|Método|Benefício|Compensação|
|------------|-------------|--------------|
|Vincular estaticamente ao CRT<br /><br /> (**Biblioteca de tempo de execução** definido como **Single-threaded**)|A DLL do CRT não é necessário no sistema em que a imagem será executado.|Cerca de 25 mil do código de inicialização é adicionado à sua imagem, aumentar substancialmente o seu tamanho.|
|Vincular dinamicamente ao CRT<br /><br /> (**Biblioteca de tempo de execução** definido como **multi-threaded**)|Sua imagem não exige o código de inicialização do CRT, portanto, é muito menor.|A DLL do CRT deve ser no sistema executando a imagem.|

O tópico [vinculando ao CRT em seu projeto de ATL](../atl/linking-to-the-crt-in-your-atl-project.md) discute como selecionar a maneira na qual deseja vincular ao CRT.

## <a name="see-also"></a>Consulte também

[Programando com código de tempo de execução C e da ATL](../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](../build/run-time-library-behavior.md)<br/>
[Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)
