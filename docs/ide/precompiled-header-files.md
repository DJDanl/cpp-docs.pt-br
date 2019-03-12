---
title: Arquivos de cabeçalho pré-compilado
ms.date: 11/04/2016
f1_keywords:
- stdafx.h
helpviewer_keywords:
- stdafx.h
- PCH files, file descriptions
- .pch files, file descriptions
- precompiled header files, file descriptions
- stdafx.cpp
ms.assetid: 8228d87a-5609-41f3-9697-b16094c000e5
ms.openlocfilehash: c9df203aac7d43c4c16850dd617639a85234917b
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57740888"
---
# <a name="precompiled-header-files"></a>Arquivos de cabeçalho pré-compilado

Esses arquivos são usados para compilar um arquivo de cabeçalho pré-compilado *Nome_do_projeto*.pch e um arquivo de tipos pré-compilados Stdafx.obj.

Esses arquivos estão localizados no diretório *Nome_do_projeto*. No Gerenciador de Soluções, Stdafx.h está na pasta Arquivos de Cabeçalho e Stdafx.cpp está localizado na pasta Arquivos de Origem.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|Stdafx.h|Um arquivo de inclusão para arquivos de inclusão do sistema padrão e para arquivos de inclusão específicos ao projeto que são usados com frequência, mas modificados raramente.<br /><br /> Não é possível definir ou remover a definição de qualquer uma das macros _AFX_NO_XXX em stdafx.h.|
|Stdafx.cpp|Contém a diretiva de pré-processador `#include "stdafx.h"` e adiciona arquivos de inclusão a tipos pré-compilados. Arquivos pré-compilados de qualquer tipo, incluindo arquivos de cabeçalho, dão suporte a tempos de compilação mais rápidos, restringindo a compilação somente aos arquivos que precisam dele. Depois que o projeto for compilado pela primeira vez, você observará tempos de build muito mais rápidos nos próximos builds, devido à presença dos arquivos de cabeçalho pré-compilado.|

## <a name="see-also"></a>Consulte também

[Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)<br>
[Trabalhando com Propriedades do Projeto](../ide/working-with-project-properties.md)
