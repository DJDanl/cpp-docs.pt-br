---
title: Exportando Classes de cadeia de caracteres usando CStringT | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- CStringT class, exporting strings
ms.assetid: bdfc441e-8d2a-461c-9885-46178066c09f
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dd662b149f56cf0d6bd5e7a3c912e0ecd14f21b9
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exporting-string-classes-using-cstringt"></a>Exportando Classes de cadeia de caracteres usando CStringT
No passado, os desenvolvedores MFC derivada de `CString` para especializar suas próprias classes de cadeia de caracteres. No Microsoft Visual C++ .NET (MFC 8.0), o [CString](../atl-mfc-shared/using-cstring.md) classe foi substituída por uma classe de modelo chamada [CStringT](../atl-mfc-shared/reference/cstringt-class.md). Isso fornecido várias vantagens:  
  
-   Permitido o MFC `CString` classe a ser usado na ATL projetos sem vinculá-lo na biblioteca estática do MFC ou DLL maior.  
  
-   Com o novo `CStringT` classe de modelo, você pode personalizar `CString` comportamento usando os parâmetros de modelo que especifique as características de caractere, semelhantes aos modelos na biblioteca C++ padrão.  
  
-   Quando você exportar sua própria classe de cadeia de caracteres de uma DLL usando `CStringT`, o compilador automaticamente exporta o `CString` classe base. Como `CString` em si é uma classe de modelo, pode ser instanciado pelo compilador quando usado, a menos que o compilador reconhece que `CString` é importado de uma DLL. Se você migrou projetos do Visual C++ 6.0 para o Visual C++ .NET, você pode ver erros de símbolo de vinculador para um definido `CString` devido a colisão do `CString` importados de uma DLL e a versão de instâncias locais. A maneira correta de fazer isso é descrita abaixo. Para obter mais informações sobre esse problema, consulte o artigo da Base de dados de Conhecimento, "vinculação erros quando você importa derivado CString Classes" (Q309801) em [http://support.microsoft.com/default.aspx](http://support.microsoft.com/default.aspx).  
  
 O cenário a seguir fará com que o vinculador gerar erros de símbolo para classes definidos várias vezes. Suponha que você estiver exportando um `CString`-classe derivada (`CMyString`) de uma DLL de extensão do MFC:  
  
 [!code-cpp[NVC_MFC_DLL#6](../atl-mfc-shared/codesnippet/cpp/exporting-string-classes-using-cstringt_1.cpp)]  
  
 O código do consumidor usa uma combinação de `CString` e `CMyString`. "MyString.h" não está incluído no cabeçalho pré-compilado e alguns usos de `CString` não tem `CMyString` visível.  
  
 Suponhamos que você use o `CString` e `CMyString` classes nos arquivos de origem separados, Source1.cpp e Source2.cpp. Source1.cpp, você usa `CMyString` e #include MyString.h. Source2.cpp, você usa `CString`, mas não #include MyString.h. Nesse caso, o vinculador emitirá um aviso sobre `CStringT` sendo definido várias vezes. Isso é causado por `CString` sendo importados da DLL que exporta `CMyString`e uma instância criada localmente pelo compilador por meio de `CStringT` modelo.  
  
 Para resolver esse problema, faça o seguinte:  
  
 Exportar `CStringA` e `CStringW` (e as classes base necessárias) de MFC90. DLL. Os projetos que incluem MFC sempre usará a DLL do MFC exportada `CStringA` e `CStringW`, como em implementações anteriores do MFC.  
  
 Em seguida, crie uma classe derivada exportável usando o `CStringT` modelo, como `CStringT_Exported` está abaixo, por exemplo:  
  
 [!code-cpp[NVC_MFC_DLL#7](../atl-mfc-shared/codesnippet/cpp/exporting-string-classes-using-cstringt_2.cpp)]  
  
 No AfxStr.h, substitua anterior `CString`, `CStringA`, e `CStringW` typedefs da seguinte maneira:  
  
 [!code-cpp[NVC_MFC_DLL#8](../atl-mfc-shared/codesnippet/cpp/exporting-string-classes-using-cstringt_3.cpp)]  
  
 Existem várias limitações:  
  
-   Você não deve exportar `CStringT` próprio porque isso fará com que somente ATL projetos exportar um especializado `CStringT` classe.  
  
-   Usar um exportável derivada a classe de `CStringT` minimiza a necessidade de reimplementar `CStringT` funcionalidade. Código adicional é limitado a encaminhamento construtores para o `CStringT` classe base.  
  
-   `CString`, `CStringA`, e `CStringW` só deve ser marcado como `__declspec(dllexport/dllimport)` quando você está criando com uma MFC DLL compartilhada. Se vincular a uma biblioteca estática do MFC, você não deve marcar essas classes exportados; Caso contrário, interno de uso de `CString`, `CStringA`, e `CStringW` dentro de usuário DLLs marcará `CString` como exportados.  
  
## <a name="related-topics"></a>Tópicos relacionados  
 [Classe CStringT](../atl-mfc-shared/reference/cstringt-class.md)  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStringT](../atl-mfc-shared/using-cstringt.md)   
 [Usando CString](../atl-mfc-shared/using-cstring.md)

