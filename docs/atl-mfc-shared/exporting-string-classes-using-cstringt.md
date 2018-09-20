---
title: Exportando Classes de cadeia de caracteres usando CStringT | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CStringT class, exporting strings
ms.assetid: bdfc441e-8d2a-461c-9885-46178066c09f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5355b6e81354ef04b7cc4d2c3495289c9d1d029d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46444197"
---
# <a name="exporting-string-classes-using-cstringt"></a>Exportando Classes de cadeia de caracteres usando CStringT

No passado, os desenvolvedores MFC derivada de `CString` especializar suas próprias classes de cadeia de caracteres. No Microsoft Visual C++ .NET (MFC 8.0), o [CString](../atl-mfc-shared/using-cstring.md) classe foi substituída por uma classe de modelo chamada [CStringT](../atl-mfc-shared/reference/cstringt-class.md). Isso forneceu vários benefícios:

- Isso permitiu o MFC `CString` classe a ser usado em ATL projetos sem vinculá-lo na biblioteca estática do MFC ou DLL maiores.

- Com o novo `CStringT` classe de modelo, você pode personalizar `CString` comportamento usando parâmetros de modelo que especifica as características de caractere, semelhantes aos modelos na biblioteca padrão C++.

- Quando você exportar sua própria classe de cadeia de caracteres de uma DLL usando `CStringT`, o compilador também automaticamente exporta o `CString` classe base. Uma vez que `CString` em si for uma classe de modelo, pode ser instanciado pelo compilador quando usado, a menos que o compilador reconhece que `CString` é importado de uma DLL. Se você migrou projetos do Visual C++ 6.0 para o Visual C++ .NET, talvez você tenha visto erros de símbolo do vinculador para um definido de forma múltipla `CString` por causa a colisão do `CString` importados de uma DLL e a versão de instâncias locais. O modo adequado para fazer isso é descrito abaixo. Para obter mais informações sobre esse problema, consulte o artigo da Base de dados de Conhecimento, "vinculação erros quando você importa CString derivado Classes" (Q309801) em [ http://support.microsoft.com/default.aspx ](http://support.microsoft.com/default.aspx).

O cenário a seguir fará com que o vinculador a produzir erros de símbolo para classes definidas várias vezes. Suponha que você estiver exportando um `CString`-classe derivada (`CMyString`) de uma DLL de extensão do MFC:

[!code-cpp[NVC_MFC_DLL#6](../atl-mfc-shared/codesnippet/cpp/exporting-string-classes-using-cstringt_1.cpp)]

O código de consumidor usa uma combinação de `CString` e `CMyString`. "MyString.h" não está incluído no cabeçalho pré-compilado e algum uso de `CString` não tem `CMyString` visível.

Suponha que você use o `CString` e `CMyString` classes em arquivos de origem separado, Source1.cpp e Source2.cpp. Source1.cpp, você usa `CMyString` e #include MyString.h. Source2.cpp, você usa `CString`, mas não #include MyString.h. Nesse caso, o vinculador vai reclamar sobre `CStringT` que está sendo definido várias vezes. Isso é causado por `CString` que estão sendo importados da DLL que exporta `CMyString`e uma instância criada localmente pelo compilador por meio de `CStringT` modelo.

Para resolver esse problema, faça o seguinte:

Exportar `CStringA` e `CStringW` (e as classes base necessárias) de MFC90. DLL. Projetos que incluem MFC sempre usará a DLL do MFC exportada `CStringA` e `CStringW`, como as implementações anteriores do MFC.

Em seguida, crie uma classe derivada exportável usando o `CStringT` modelo, como `CStringT_Exported` está abaixo, por exemplo:

[!code-cpp[NVC_MFC_DLL#7](../atl-mfc-shared/codesnippet/cpp/exporting-string-classes-using-cstringt_2.cpp)]

No AfxStr.h, substitua anterior `CString`, `CStringA`, e `CStringW` typedefs da seguinte maneira:

[!code-cpp[NVC_MFC_DLL#8](../atl-mfc-shared/codesnippet/cpp/exporting-string-classes-using-cstringt_3.cpp)]

Existem várias advertências:

- Você deve exportar `CStringT` em si porque isso fará com que projetos de ATL-somente exportar especializado `CStringT` classe.

- Usando um exportável derivadas da classe de `CStringT` minimiza a necessidade de implementar novamente `CStringT` funcionalidade. Um código adicional é limitado a construtores de encaminhamento a `CStringT` classe base.

- `CString`, `CStringA`, e `CStringW` só deve ser marcado como `__declspec(dllexport/dllimport)` quando você está criando com um MFC compartilhado DLL. Se vincular a uma biblioteca estática do MFC, você não deve marcar essas classes como a exportação; Caso contrário, interno de uso de `CString`, `CStringA`, e `CStringW` dentro do usuário DLLs marcará `CString` como também a exportação.

## <a name="related-topics"></a>Tópicos relacionados

[Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)

## <a name="see-also"></a>Consulte também

[Usando CStringT](../atl-mfc-shared/using-cstringt.md)<br/>
[Usando CString](../atl-mfc-shared/using-cstring.md)

