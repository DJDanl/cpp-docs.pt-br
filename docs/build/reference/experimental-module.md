---
title: '/experimental: módulo (habilitar suporte a módulo)'
description: 'Use a opção de compilador/experimental: Module para habilitar o suporte experimental do compilador para módulos.'
ms.date: 09/03/2019
f1_keywords:
- module
- /experimental:module
helpviewer_keywords:
- module
- /experimental:module
- Enable module support
ms.openlocfilehash: 82cce127ad5a2f87d11e4a653035bd80ea9f5001
ms.sourcegitcommit: fd0f8839da5c6a3663798a47c6b0bb6e63b518bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2019
ms.locfileid: "70294453"
---
# <a name="experimentalmodule-enable-module-support"></a>/experimental: módulo (habilitar suporte a módulo)

Habilita o suporte experimental a compilador para módulos, conforme especificado pelo rascunho de C++ 20 padrão.

## <a name="syntax"></a>Sintaxe

> **/experimental: módulo** [ **-** ]

## <a name="remarks"></a>Comentários

Você pode habilitar o suporte a módulos experimentais usando a opção de compilador **/experimental: module** juntamente com a opção [/std: c + + mais recente](std-specify-language-standard-version.md) . Você pode usar **/experimental: module-** para desabilitar o suporte de módulo explicitamente.

Essa opção está disponível a partir do Visual Studio 2015 atualização 1. A partir do Visual Studio 2019 versão 16,2, Draft C++ 20 módulos padrão não são totalmente implementados no C++ compilador da Microsoft. Você pode usar o recurso de módulos para criar módulos de partição única e para importar os módulos de biblioteca padrão fornecidos pela Microsoft. Um módulo e o código que o consome devem ser compilados com as mesmas opções de compilador.

Para obter mais informações sobre módulos e como usá-los e criá-los, consulte [visão C++geral dos módulos no ](../../cpp/modules-cpp.md).

Aqui está um exemplo das opções de linha de comando do compilador usadas para criar um módulo de exportação do arquivo de origem *ModuleName. IXX*:

```cmd
cl /EHsc /MD /experimental:module /module:export /module:name ModuleName /module:wrapper C:\Output\path\ModuleName.h /module:output C:\Output\path\ModuleName.ifc -c ModuleName.ixx
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Defina a lista suspensa **configuração** para **todas as configurações**.

1. Selecione a página de **Propriedades** >  > configuração**C/C++** **idioma** .

1. Modifique a **propriedade C++ habilitar módulos (experimental)** e escolha **OK**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)
