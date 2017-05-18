---
title: Classe ctype&lt;char&gt; | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ctype<char>
- locale/std::ctype<char>
dev_langs:
- C++
helpviewer_keywords:
- ctype<char> class
ms.assetid: ee30acb4-a743-405e-b3d4-13602092da84
caps.latest.revision: 20
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 66798adc96121837b4ac2dd238b9887d3c5b7eef
ms.openlocfilehash: 28fc5cf88c6a50b5fcd9950b68d7c6ef3529ccee
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="ctypeltchargt-class"></a>Classe ctype&lt;char&gt;
Uma classe que é uma especialização explícita da classe de modelo **ctype\<CharType**> para o tipo `char`, que descreve um objeto que pode servir como uma faceta de localidade para caracterizar várias propriedades de um caractere do tipo `char`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <>  
class ctype<char>  
: public ctype_base  
{  
public:  
    typedef char _Elem;  
    typedef _Elem char_type;  
    bool is(
    mask _Maskval,  
    _Elem _Ch) const;

 
    const _Elem* is(
    const _Elem* first,  
    const _Elem* last,  
    mask* dest) const;

 
    const _Elem* scan_is(
    mask _Maskval,  
    const _Elem* first,  
    const _Elem* last) const;

 
    const _Elem* scan_not(
    mask _Maskval,  
    const _Elem* first,  
    const _Elem* last) const;

 
    _Elem tolower(
    _Elem _Ch) const;

 
    const _Elem* tolower(
    _Elem* first,  
    const _Elem* last) const;

 
    _Elem toupper(
    _Elem _Ch) const;

 
    const _Elem* toupper(
    _Elem* first,  
    const _Elem* last) const;

 
    _Elem widen(
    char _Byte) const;

 
    const _Elem* widen(
    const char* first,  
    const char* last,  
    _Elem* dest) const;

 
    const _Elem* _Widen_s(
    const char* first,  
    const char* last,  
    _Elem* dest,  
    size_t dest_size) const;

 
    _Elem narrow(
    _Elem _Ch,  
    char _Dflt = '\0') const;

 
    const _Elem* narrow(
    const _Elem* first,  
    const _Elem* last,  
    char _Dflt,  
    char* dest) const;

 
    const _Elem* _Narrow_s(
    const _Elem* first,  
    const _Elem* last,  
    char _Dflt,  
    char* dest,  
    size_t dest_size) const;

 
    static locale::id& id;  
    explicit ctype(
    const mask* _Table = 0,  
    bool _Deletetable = false,  
    size_t _Refs = 0);

protected:  
    virtual ~ctype();
//other protected members  
};  
```  
  
## <a name="remarks"></a>Comentários  
 A especialização explícita é diferente da classe de modelo de várias maneiras:  
  
-   Um objeto da classe ctype< `char`> armazena um ponteiro para o primeiro elemento de uma tabela de máscara ctype, uma matriz de elementos UCHAR_MAX + 1 do tipo **ctype_base::mask**. Ele também armazena um objeto booliano que indica se a matriz deve ser excluída (usando `operator delete[]`) quando o objeto ctype\< **Elem**> é destruído.  
  
-   Seu único construtor público permite especificar **tab**, a tabela de máscara ctype e **del**, o objeto booliano que será verdadeiro se a matriz precisar ser excluída quando o objeto ctype< `char`> for destruído, bem como as referências de parâmetro de contagem de referência.  
  
-   A função de membro protegida **table** retorna a tabela de máscara ctype armazenada.  
  
-   O objeto de membro estático **table_size** especifica o número mínimo de elementos em uma tabela de máscara ctype.  
  
-   A função de membro estático protegida **classic_table**( retorna a tabela de máscara ctype apropriada para a localidade “C”.  
  
-   Não existem funções de membro virtuais protegidas [do_is](../standard-library/ctype-class.md#do_is), [do_scan_is](../standard-library/ctype-class.md#do_scan_is) ou [do_scan_not](../standard-library/ctype-class.md#do_scan_not). As funções de membro público correspondentes executam as operações equivalentes por conta própria.  
  
 As funções de membro [do_narrow](../standard-library/ctype-class.md#do_narrow) e [do_widen](../standard-library/ctype-class.md#do_widen) copiam os elementos inalterados.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<locale>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Classe facet](http://msdn.microsoft.com/Library/dd4f12f5-cb1b-457f-af56-2fb204216ec1)   
 [Classe ctype_base](../standard-library/ctype-base-class.md)   
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)


