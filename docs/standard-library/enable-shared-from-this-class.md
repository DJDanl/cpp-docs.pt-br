---
title: Classe enable_shared_from_this | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- enable_shared_from_this
- memory/std::enable_shared_from_this
dev_langs:
- C++
helpviewer_keywords:
- enable_shared_from_this class
- enable_shared_from_this
ms.assetid: 9237603d-22e2-421f-b070-838ac006baf5
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.openlocfilehash: bfe398bf4829d6ef86543890bea28a351bcb4a3d
ms.contentlocale: pt-br
ms.lasthandoff: 04/29/2017

---
# <a name="enablesharedfromthis-class"></a>Classe enable_shared_from_this
Ajuda a gerar um `shared_ptr`.  
  
## <a name="syntax"></a>Sintaxe  
```    
class enable_shared_from_this {
public:
    shared_ptr<Ty>
        shared_from_this();
    shared_ptr<const Ty> shared_from_this() const;
protected:
    enable_shared_from_this();
    enable_shared_from_this(const enable_shared_from_this&);
    enable_shared_from_this& operator=(const enable_shared_from_this&);
    ~enable_shared_from_this();
}; 
``` 
#### <a name="parameters"></a>Parâmetros  
 `Ty`  
 O tipo controlado pelo ponteiro compartilhado.  
  
## <a name="remarks"></a>Comentários  
 Os objetos derivados de `enable_shared_from_this` podem usar os métodos `shared_from_this` nas funções de membro para criar proprietários de instância [shared_ptr](../standard-library/shared-ptr-class.md) que compartilham a propriedade com proprietários `shared_ptr` existentes. Caso contrário, se você criar um novo `shared_ptr` usando `this`, ele será diferente dos proprietários `shared_ptr` existentes, o que poderá levar a referências inválidas ou fazer com que o objeto seja excluído mais de uma vez.  
  
 Os construtores, o destruidor e o operador de atribuição são protegidos para evitar o uso indevido acidental. O tipo de argumento de modelo `Ty` deve ser do tipo da classe derivada.  
  
 Para obter um exemplo de uso, consulte [enable_shared_from_this::shared_from_this](#shared_from_this).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<memory>  
  
 **Namespace:** std  
  
##  <a name="shared_from_this"></a>  enable_shared_from_this::shared_from_this  
 Gera um `shared_ptr` que compartilha a propriedade da instância com proprietários `shared_ptr` existentes.  
  
```  
shared_ptr<T> shared_from_this();
shared_ptr<const T> shared_from_this() const;
```  
  
### <a name="remarks"></a>Comentários  
 Quando você deriva objetos da classe base `enable_shared_from_this`, as funções de membro de modelo `shared_from_this` retornam um objeto de [Classe shared_ptr](../standard-library/shared-ptr-class.md) que compartilha a propriedade dessa instância com os proprietários `shared_ptr` existentes. Caso contrário, se você criar um novo `shared_ptr` de `this`, ele será diferente dos proprietários `shared_ptr` existentes, o que poderá levar a referências inválidas ou fazer com que o objeto seja excluído mais de uma vez. O comportamento será indefinido se você chamar `shared_from_this` em uma instância que já não pertence a um objeto `shared_ptr`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// std_memory_shared_from_this.cpp   
// compile with: /EHsc   
#include <memory>  
#include <iostream>  
  
using namespace std;  
  
struct base : public std::enable_shared_from_this<base>  
{  
    int val;    
    shared_ptr<base> share_more()  
    {  
        return shared_from_this();  
    }  
};  
  
int main()  
{  
    auto sp1 = make_shared<base>();  
    auto sp2 = sp1->share_more();  
  
    sp1->val = 3;  
    cout << "sp2->val == " << sp2->val << endl;    
    return 0;  
}   
```  
  
```Output  
sp2->val == 3  
```  
  
## <a name="see-also"></a>Consulte também  
 [enable_shared_from_this::shared_from_this](#shared_from_this)   
 [Classe shared_ptr](../standard-library/shared-ptr-class.md)
