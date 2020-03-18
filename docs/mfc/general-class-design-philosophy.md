---
title: Filosofia de design da classe geral
ms.date: 11/04/2016
helpviewer_keywords:
- designing classes [MFC]
- MFC, Windows API
- Visual C, Windows API calls
- classes [MFC], MFC class design
- Windows API [MFC], and MFC
ms.assetid: e6861ae0-1581-4d9c-9ddf-63f9afcdb913
ms.openlocfilehash: 34a173802e3fa43615c05da4ce747592f851228f
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79441193"
---
# <a name="general-class-design-philosophy"></a>Filosofia de design da classe geral

O Microsoft Windows foi projetado muito antes C++ que a linguagem se tornou popular. Como milhares de aplicativos usam a API (interface de programação de aplicativo) do Windows em linguagem C, essa interface será mantida para o futuro próximo. Portanto C++ , qualquer interface do Windows deve ser criada sobre o procedimento da API C-Language. Isso garante que C++ os aplicativos poderão coexistir com os aplicativos C.

O biblioteca MFC é uma interface orientada a objeto para o Windows que atende às seguintes metas de design:

- Redução significativa no esforço para escrever um aplicativo para o Windows.

- Velocidade de execução comparável à da API de linguagem C.

- Sobrecarga mínima do tamanho do código.

- Capacidade de chamar qualquer função do Windows C diretamente.

- Conversão mais fácil de aplicativos C existentes C++no.

- Capacidade de aproveitar a base existente da experiência de programação do Windows em linguagem C.

- Uso mais fácil da API do Windows C++ com a C.

- Abstrações mais fáceis de usar, porém, poderosas de recursos complicados, como controles ActiveX, suporte a banco de dados, impressão, barras de ferramentas e barras de status.

- A verdadeira API do C++ Windows para usar C++ efetivamente os recursos de linguagem.

Para obter mais informações sobre o design da biblioteca do MFC, consulte:

- [A estrutura do aplicativo](../mfc/application-framework.md)

- [Relacionamento com a API da linguagem C](../mfc/relationship-to-the-c-language-api.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
