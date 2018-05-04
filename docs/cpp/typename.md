---
title: TypeName | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- typename_cpp
dev_langs:
- C++
helpviewer_keywords:
- typename template specifier
ms.assetid: 52e1d901-220d-4f0d-ab43-dae7e05fb491
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6eebf038fbe3e5e18e3f2a1e8e7a2aa2554bf41
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="typename"></a>typename
Em definições de modelo fornece uma dica para o compilador que um identificador desconhecido é um tipo. Listas de parâmetros de modelo, é usado para especificar um parâmetro de tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
typename identifier;  
```  
  
## <a name="remarks"></a>Comentários  
 Esta palavra-chave deve ser usada se um nome de uma definição de modelo é um nome qualificado que é dependente de um argumento de modelo. é opcional se o nome qualificado não é dependente. Para obter mais informações, consulte [modelos e resolução de nome](../cpp/templates-and-name-resolution.md).  
  
 **TypeName** pode ser usado por qualquer tipo em qualquer lugar em uma declaração de modelo ou a definição. Não é permitido na lista de classes base, a menos que como um argumento de modelo para uma classe base de modelo.  
  
```  
template <class T>  
class C1 : typename T::InnerType // Error - typename not allowed.  
{};  
template <class T>  
class C2 : A<typename T::InnerType>  // typename OK.  
{};  
```  
  
 O **typename** palavra-chave também pode ser usado no lugar de **classe** no parâmetro de modelo de lista. Por exemplo, as instruções a seguir são semanticamente equivalentes:  
  
```  
template<class T1, class T2>...  
template<typename T1, typename T2>...  
```  
  
## <a name="example"></a>Exemplo  
  
```  
// typename.cpp  
template<class T> class X  
{  
   typename T::Y m_y;   // treat Y as a type  
};  
  
int main()  
{  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Modelos](../cpp/templates-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)