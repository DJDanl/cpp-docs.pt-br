---
title: Sintaxe de partes do nome de arquivo
ms.date: 11/04/2016
helpviewer_keywords:
- syntax, filename-parts
- filename-parts syntax in NMAKE
- NMAKE program, syntax
ms.assetid: 48fe38e0-3f3b-40e6-894c-330ee775a656
ms.openlocfilehash: d5e815dcb8a424d309362e004d1de4c039dc968b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62292647"
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

- %s will be c:\prog.exe

- %&#124;F will be c:\prog.exe

- %&#124;dF será c

- %&#124;pF will be c:\

- %&#124;fF será prog

- %&#124;eF estará exe

## <a name="see-also"></a>Consulte também

[Comandos em um makefile](commands-in-a-makefile.md)
