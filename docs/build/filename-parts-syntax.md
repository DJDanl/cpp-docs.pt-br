---
title: Sintaxe de partes do nome de arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- syntax, filename-parts
- filename-parts syntax in NMAKE
- NMAKE program, syntax
ms.assetid: 48fe38e0-3f3b-40e6-894c-330ee775a656
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5bf7a9685face739059c4b947a5796cc0a28950a
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45703164"
---
# <a name="filename-parts-syntax"></a>Sintaxe de partes do nome de arquivo

Sintaxe de partes de nome de arquivo em comandos representa os componentes do nome de arquivo dependente primeiro (o que pode ser um dependente implícita). Componentes de nome de arquivo são a unidade, caminho, nome de base e extensão conforme especificado, o arquivo não conforme ele existe no disco. Use **%s** para representar o nome de arquivo completo. Use **%&#124;**[*partes*]**F** (uma barra vertical caractere segue o símbolo de porcentagem) para representar as partes do nome de arquivo, onde *partes*pode ser zero ou mais das seguintes letras, em qualquer ordem.

|Letra|Descrição|
|------------|-----------------|
|Nenhuma letra|Nome completo (mesmo que **%s**)|
|**d**|Dirigir|
|**p**|Caminho|
|**f**|Nome base do arquivo|
|**e**|Extensão de arquivo|

Por exemplo, se o nome do arquivo é c:\prog.exe:

- %s será c:\prog.exe

- %&#124;F será c:\prog.exe

- %&#124;dF será c

- %&#124;pF será c:\

- %&#124;fF será prog

- %&#124;eF estará exe

## <a name="see-also"></a>Consulte também

[Comandos em um makefile](../build/commands-in-a-makefile.md)