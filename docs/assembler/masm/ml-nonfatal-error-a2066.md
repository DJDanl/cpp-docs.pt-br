---
title: Erro não fatal de ML A2066 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2066
dev_langs:
- C++
helpviewer_keywords:
- A2066
ms.assetid: 58220fdf-fb8f-47fc-a36d-737867361185
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8cf5cbe7d5c77da7f129cbc40ffa97f4051afca6
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43690246"
---
# <a name="ml-nonfatal-error-a2066"></a>Erro não fatal A2066 (ML)

**tamanho incompatível de modo e o segmento da CPU**

Foi feita uma tentativa para abrir um segmento com uma **USE16**, **USE32**, ou **simples** atributo que não era compatível com a CPU especificada ou para alterar para uma CPU de 16 bits em 32 bits segmento.

O **USE32** e **simples** atributos devem ser precedidos pela. 386 de ou diretiva de processador maior.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>