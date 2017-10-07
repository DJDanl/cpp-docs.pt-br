---
title: Classe type_info | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- type_info
dev_langs:
- C++
helpviewer_keywords:
- class type_info
- type_info class
ms.assetid: 894ddda2-7de4-4da3-9404-d2c74e356c16
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: b87dec1f3d3a04d984c3bbd96344ebcb0a163f19
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="typeinfo-class"></a>Classe type_info
O **type_info** classe descreve as informações de tipo geradas dentro do programa pelo compilador. Os objetos dessa classe armazenam efetivamente um ponteiro para um nome do tipo. O **type_info** classe também armazena um valor codificado adequado para comparar dois tipos de igualdade ou ordem de agrupamento. As regras e a sequência de agrupamento de codificação para tipos não são especificados e podem ser diferentes entre os programas.  
  
 O `<typeinfo>` arquivo de cabeçalho deve ser incluído para usar o **type_info** classe. A interface para o **type_info** classe é:  
  
```cpp
class type_info {  
public:  
    virtual ~type_info();  
    size_t hash_code() const  
    _CRTIMP_PURE bool operator==(const type_info& rhs) const;  
    _CRTIMP_PURE bool operator!=(const type_info& rhs) const;  
    _CRTIMP_PURE int before(const type_info& rhs) const;  
    _CRTIMP_PURE const char* name() const;  
    _CRTIMP_PURE const char* raw_name() const;  
};  
```  
  
 Não é possível instanciar objetos do **type_info** classe diretamente, porque a classe tem apenas um construtor de cópia particular. A única maneira de construir (temporário) **type_info** objeto é usar o [typeid](../cpp/typeid-operator.md) operador. Como o operador de atribuição também é privado, você não pode copiar ou atribuir objetos da classe **type_info**.  
  
 **type_info::hash_code** define uma função de hash adequada para mapeamento de valores do tipo **typeinfo** para uma distribuição de valores de índice.  
  
 Os operadores `==` e `!=` pode ser usado para comparar quanto à igualdade e desigualdade com outros **type_info** objetos, respectivamente.  
  
 Não há nenhum link entre a ordem de agrupamento de tipos e relações de herança. Use o **type_info::before** a função de membro para determinar a sequência de agrupamento de tipos. Não há nenhuma garantia que **type_info::before** produzirá o mesmo resultado em diferentes programas ou execuções diferentes do mesmo programa. Dessa maneira, **type_info::before** é semelhante para o endereço de **(&)** operador.  
  
 O **type_info::name** função membro retorna um **char const\* ** para uma cadeia de caracteres terminada em nulo que representa o nome legível do tipo. A memória apontada é armazenada em cache e nunca deve ser desalocada diretamente.  
  
 O **type_info::raw_name** função membro retorna um **char const\* ** para uma cadeia de caracteres terminada em nulo que representa o nome decorado do tipo de objeto. O nome é armazenado em sua forma decorada para economizar espaço. Consequentemente, essa função é mais rápida que **type_info::name** porque ele não precisa undecorate o nome. A cadeia de caracteres retornada pelo **type_info::raw_name** função é útil para operações de comparação, mas não é legível. Se você precisar de uma cadeia de caracteres legível, use o **type_info::name** function em vez disso.  
  
 Informações de tipo são geradas se somente classes polimórficas o [/GR (Habilitar informações de tipo em tempo de execução)](../build/reference/gr-enable-run-time-type-information.md) opção de compilador é especificada.  
  
## <a name="see-also"></a>Consulte também  
 [Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)

