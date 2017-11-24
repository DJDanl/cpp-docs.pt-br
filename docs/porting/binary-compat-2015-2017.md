---
title: "Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2017 | Microsoft Docs"
ms.custom: 
ms.date: 09/21/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: binary compatibility, Visual C++
ms.assetid: 591580f6-3181-4bbe-8ac3-f4fbaca949e6
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 89bb772976050c8ebf0b7745aa0541c2de3e2fed
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-binary-compatibility-between-visual-studio-2015-and-visual-studio-2017"></a>Compatibilidade binária de C++ entre o Visual Studio 2015 e o Visual Studio 2017


Em versões anteriores do Visual Studio, não havia garantia de compatibilidade binária entre arquivo-objetos (OBJs), bibliotecas estáticas (LIBs), bibliotecas dinâmicas (DLLs) e executáveis (EXEs) compilados com versões diferentes do conjunto de ferramentas do computador e das bibliotecas de tempo de execução. Isso mudou no Visual Studio 2017. No Visual Studio 2015 e no Visual Studio 2017, o número principal do conjunto de ferramentas do C++ é 14 (v140 para Visual Studio 2015 e v141 para Visual Studio 2017). Isso reflete o fato de que tanto as bibliotecas de tempo de execução quanto os aplicativos compilados com uma das versões do compilador apresentam, em grande parte, compatibilidade binária. Isso significa, por exemplo, que você pode criar uma DLL no Visual Studio 2017 e consumi-lo em um aplicativo compilado com o Visual Studio 2015 ou usar as bibliotecas redistribuíveis do Visual Studio 2017 com o aplicativo compilado usando o conjunto de ferramentas de 2015.  

Há duas exceções a essa regra. Não há garantia de compatibilidade binária nesses casos:  

1) Quando as bibliotecas estáticas ou arquivos-objetos são compilados com a opção /GL de compilador.  

2) Quando o aplicativo consome bibliotecas redistribuíveis cujo número de versão é menor que o conjunto de ferramentas usado para compilar o aplicativo. Em outras palavras, se você compilar um programa com o conjunto de ferramentas da plataforma v141, as bibliotecas redistribuíveis que o aplicativo consumir deverão ser compiladas com v141 ou superior.  

## <a name="see-also"></a>Consulte também  

[Histórico de alterações do Visual C++](..\porting\visual-cpp-change-history-2003-2015.md)


